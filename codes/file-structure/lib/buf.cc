#include "buf.h"
#include <string>

using namespace std;

/// IOBuffer

static const char *IOBufferHeaderStr = "IOBuffer";
static const int IOBufferHeaderSize = strlen (IOBufferHeaderStr);

IOBuffer::IOBuffer (int maxBytes) { Init (maxBytes); }

IOBuffer &
IOBuffer::operator= (const IOBuffer &buffer)
{
  if (_maxBytes < buffer._bufferSize)
    return *this;

  _initialized = buffer._initialized;
  _bufferSize = buffer._bufferSize;
  memcpy (_buffer, buffer._buffer, buffer._bufferSize);
  _nextByte = buffer._nextByte;
  _packing = buffer._packing;
  return *this;
}

void
IOBuffer::Clear ()
{
  _nextByte = 0;
  _packing = true;
}

void
IOBuffer::Print (ostream &stream) const
{
  stream << "_maxBytes=" << _maxBytes << ", _bufferSize=" << _bufferSize;
}

int
IOBuffer::Init (int maxBytes)
{
  _initialized = false;
  if (maxBytes < 0)
    maxBytes = 0;
  _maxBytes = maxBytes;

  _buffer = new char[_maxBytes];
  _bufferSize = 0;
  Clear ();
  return 1;
}

int
IOBuffer::DRead (istream &stream, int recref)
{
  stream.seekg (recref, ios::beg);
  if (stream.tellg () != recref)
    return -1;
  return Read (stream);
}
int
IOBuffer::DWrite (ostream &stream, int recref) const
{
  stream.seekp (recref, ios::beg);
  if (stream.tellp () != recref)
    return -1;
  return Write (stream);
}

int
IOBuffer::ReadHeader (istream &stream)
{
  char str[IOBufferHeaderSize + 1];
  stream.seekg (0, ios::beg);
  stream.read (str, IOBufferHeaderSize);
  if (!stream.good ())
    return -1;
  if (strncmp (str, IOBufferHeaderStr, IOBufferHeaderSize) == 0)
    return IOBufferHeaderSize;
  else
    return -1;
}

int
IOBuffer::WriteHeader (ostream &stream) const
{
  stream.seekp (0, ios::beg);
  stream.write (IOBufferHeaderStr, IOBufferHeaderSize);
  if (!stream.good ())
    return -1;
  else
    return IOBufferHeaderSize;
}

/// VariableLengthBuffer

const char *VariableLengthBufferHeaderStr = "Variable";
const int VariableLengthBufferHeaderSize
    = strlen (VariableLengthBufferHeaderStr);

VariableLengthBuffer::VariableLengthBuffer (int maxBytes) : IOBuffer (maxBytes)
{
  Init ();
}

void
VariableLengthBuffer::Clear ()
{
  IOBuffer::Clear ();
}

int
VariableLengthBuffer::Read (istream &stream)
{
  if (stream.eof ())
    return -1;

  int recaddr = stream.tellg ();
  Clear ();

  unsigned short bufferSize;
  stream.read ((char *)&bufferSize, sizeof (bufferSize));
  if (!stream.good ())
    {
      stream.clear ();
      return -1;
    }

  _bufferSize = bufferSize;
  if (_bufferSize > _maxBytes)
    return -1;
  stream.read (_buffer, _bufferSize);
  if (!stream.good ())
    {
      stream.clear ();
      return -1;
    }

  return recaddr;
}

int
VariableLengthBuffer::Write (ostream &stream) const
{
  int recaddr = stream.tellp ();
  unsigned short bufferSize;
  bufferSize = _bufferSize;

  stream.write ((char *)&bufferSize, sizeof (bufferSize));
  if (!stream)
    return -1;
  stream.write (_buffer, _bufferSize);
  if (!stream.good ())
    return -1;
  return recaddr;
}

int
VariableLengthBuffer::ReadHeader (istream &stream)
{
  char str[VariableLengthBufferHeaderSize + 1];
  int result;
  result = IOBuffer::ReadHeader (stream);
  if (!result)
    return false;

  stream.read (str, VariableLengthBufferHeaderSize);
  if (!stream.good ())
    return false;

  if (strncmp (str, VariableLengthBufferHeaderStr,
               VariableLengthBufferHeaderSize)
      != 0)
    return false;

  return stream.tellg ();
}
int
VariableLengthBuffer::WriteHeader (ostream &stream) const
{
  int result;
  result = IOBuffer::WriteHeader (stream);
  if (!result)
    return false;

  stream.write (VariableLengthBufferHeaderStr, VariableLengthBufferHeaderSize);
  if (!stream.good ())
    return false;

  return stream.tellp ();
}

void
VariableLengthBuffer::Print (ostream &stream) const
{
  IOBuffer::Print (stream);
}

int
VariableLengthBuffer::Init ()
{
  Clear ();
  return true;
}

/// DelimFieldBuffer

DelimFieldBuffer::DelimFieldBuffer (char delim, int maxBytes)
    : VariableLengthBuffer (maxBytes)
{
  Init (delim);
}

int
DelimFieldBuffer::Pack (const void *field, int size)
{
  short len;
  if (size >= 0)
    len = size;
  else
    len = strlen ((char *)field);
  if (len > (short)strlen ((char *)field))
    return -1;

  int start = _nextByte;
  _nextByte += len + 1;
  if (_nextByte > _maxBytes)
    return -1;

  memcpy (&_buffer[start], field, len);
  _buffer[start + len] = _delim;
  _bufferSize = _nextByte;
  return len;
}

int
DelimFieldBuffer::Unpack (void *field, int maxBytes)
{
  int len = -1;
  int start = _nextByte;
  for (int i = start; i < _bufferSize; i++)
    {
      if (_buffer[i] == _delim)
        {
          len = i - start;
          break;
        }
    }
  if (len == -1)
    return -1;

  _nextByte += len + 1;
  if (_nextByte > _bufferSize)
    return -1;

  memcpy (field, &_buffer[start], len);
  if (_maxBytes > len || _maxBytes == -1)
    ((char *)field)[len] = 0;

  return len;
}

int
DelimFieldBuffer::ReadHeader (istream &stream)
{
  char ch;
  int result;
  result = VariableLengthBuffer::ReadHeader (stream);
  if (!result)
    return false;

  stream.get (ch);
  if (!_initialized)
    {
      SetDefaultDelim (ch);
      return true;
    }

  if (ch != _delim)
    return false;
  return stream.tellg ();
}

int
DelimFieldBuffer::WriteHeader (ostream &stream) const
{
  if (!_initialized)
    return false;
  int result;
  result = VariableLengthBuffer::WriteHeader (stream);
  if (!result)
    return false;

  stream.put (_delim);
  return stream.tellp ();
}

void
DelimFieldBuffer::Print (ostream &stream) const
{
  VariableLengthBuffer::Print (stream);
  stream << " Delimeter=" << _delim << endl;
}

int
DelimFieldBuffer::Init (char delim)
{
  _initialized = true;
  Clear ();
  if (delim == -1)
    _delim = DefaultDelim;
  else
    _delim = delim;

  return true;
}

void
DelimFieldBuffer::SetDefaultDelim (char delim)
{
  DefaultDelim = delim;
}

char DelimFieldBuffer::DefaultDelim = 0;

/// LengthFieldBuffer

LengthFieldBuffer::LengthFieldBuffer (int maxBytes)
    : VariableLengthBuffer (maxBytes)
{
  Init ();
}

void
LengthFieldBuffer::Clear ()
{
  VariableLengthBuffer::Clear ();
}

int
LengthFieldBuffer::Pack (const void *field, int size)
{
  short len;
  if (size >= 0)
    len = size;
  else
    len = strlen ((char *)field);
  int start = _nextByte;
  _nextByte += (len + sizeof (len));
  if (_nextByte > _maxBytes)
    return -1;

  memcpy (&_buffer[start], &len, sizeof (len));
  memcpy (&_buffer[start + sizeof (len)], field, len);

  _bufferSize = _nextByte;
  return len;
}

int
LengthFieldBuffer::Unpack (void *field, int maxBytes)
{
  short len;
  if (_nextByte >= _bufferSize)
    return -1;
  int start = _nextByte;
  memcpy (&len, &_buffer[start], sizeof (len));

  if (_maxBytes != -1 && len > _maxBytes)
    return -1;

  _nextByte += (len + sizeof (len));
  if (_nextByte > _bufferSize)
    return -1;

  memcpy (field, &_buffer[start + sizeof (len)], len);
  if (_maxBytes > len || _maxBytes == -1)
    ((char *)field)[len] = 0;

  return len;
}

void
LengthFieldBuffer::Print (ostream &stream) const
{
  stream << "Buffer has characters " << _maxBytes << " and Buffer Szie "
         << _bufferSize << endl;
}

int
LengthFieldBuffer::Init ()
{
  _initialized = true;
  Clear ();
  return true;
}

/// FixedLengthBuffer

static const char *FixedLengthBufferHeaderStr = "Fixed";
static const int FixedLengthBufferHeaderSize
    = strlen (FixedLengthBufferHeaderStr);

FixedLengthBuffer::FixedLengthBuffer (int recordSize) : IOBuffer (recordSize)
{
  Init (recordSize);
}

void
FixedLengthBuffer::Clear ()
{
  IOBuffer::Clear ();
  _buffer[0] = 0;
  _packing = true;
}

int
FixedLengthBuffer::Read (istream &stream)
{
  int recaddr = stream.tellg ();
  stream.clear ();
  Clear ();
  _packing = false;
  stream.read (_buffer, _bufferSize);
  if (!stream.good ())
    {
      stream.clear ();
      return recaddr;
    }

  return recaddr;
}

int
FixedLengthBuffer::Write (ostream &stream) const
{
  int recaddr = stream.tellp ();
  stream.write (_buffer, _bufferSize);
  if (!stream.good ())
    return -1;
  return recaddr;
}

int
FixedLengthBuffer::ReadHeader (istream &stream)
{
  char str[FixedLengthBufferHeaderSize + 1];
  int recordSize;
  int result;

  result = IOBuffer::ReadHeader (stream);
  if (result < 0)
    return -1;

  stream.read (str, FixedLengthBufferHeaderSize);
  if (!stream.good ())
    return -1;

  if (strncmp (str, FixedLengthBufferHeaderStr, FixedLengthBufferHeaderSize)
      != 0)
    return -1;

  stream.read ((char *)&recordSize, sizeof (recordSize));

  if (_initialized)
    {
      if (recordSize != _bufferSize)
        return -1;
    }

  ChangeRecordSize (recordSize);
  return stream.tellg ();
}

int
FixedLengthBuffer::WriteHeader (ostream &stream) const
{
  int result;
  if (!_initialized)
    return -1;
  result = IOBuffer::WriteHeader (stream);
  if (!result)
    return -1;

  stream.write (FixedLengthBufferHeaderStr, FixedLengthBufferHeaderSize);
  if (!stream.good ())
    return -1;

  stream.write ((char *)&_bufferSize, sizeof (_bufferSize));
  if (!stream.good ())
    return -1;
  return stream.tellp ();
}

void
FixedLengthBuffer::Print (ostream &stream) const
{
  IOBuffer::Print (stream);
  stream << "Fixed ";
}

int
FixedLengthBuffer::Init (int recordSize)
{
  Clear ();
  _bufferSize = recordSize;
  return 1;
}

int
FixedLengthBuffer::ChangeRecordSize (int recordSize)
{
  _bufferSize = recordSize;
  return 1;
}

/// FixedFieldBuffer

static const char *FixedFieldBufferHeaderStr = "Field";
static const int FixedFieldBufferHeaderSize
    = strlen (FixedFieldBufferHeaderStr);

FixedFieldBuffer::FixedFieldBuffer (int maxFields, int maxBytes)
    : FixedLengthBuffer (maxBytes)
{
  Init (maxFields);
}

// calculate the record size from the fields sizes
static int
SumFieldSizes (int numFields, int *fieldSize)
{
  int sum = 0;
  for (int i = 0; i < numFields; i++)
    sum += fieldSize[i];
  return sum;
}

FixedFieldBuffer &
FixedFieldBuffer::operator= (const FixedFieldBuffer &buffer)
{
  if (_numFields != buffer._numFields)
    return *this;

  for (int i = 0; i < _numFields; i++)
    {
      if (_fieldSize[i] != buffer._fieldSize[i])
        return *this;
    }
  _nextField = buffer._nextField;
  FixedLengthBuffer::operator= (buffer);
  return *this;
}

FixedFieldBuffer::FixedFieldBuffer (int numFields, int *fieldSize)
    : FixedLengthBuffer (SumFieldSizes (numFields, fieldSize))
{
  Init (numFields, fieldSize);
}

int
FixedFieldBuffer::NumberOfFields () const
{
  return _numFields;
}

void
FixedFieldBuffer::Clear ()
{
  FixedLengthBuffer::Clear ();
  _nextField = 0;
  _buffer[0] = 0;
  _packing = true;
}

int
FixedFieldBuffer::AddField (int fieldSize)
{
  _initialized = true;
  if (_numFields == _maxFields)
    return false;

  if (_bufferSize + fieldSize > _maxBytes)
    return false;

  _fieldSize[_numFields] = fieldSize;
  _numFields++;
  _bufferSize += fieldSize;
  return true;
}

int
FixedFieldBuffer::ReadHeader (istream &stream)
{
  char *str = new char[FixedFieldBufferHeaderSize + 1];
  int numFields, *fieldSize;
  int result;

  result = FixedLengthBuffer::ReadHeader (stream);
  if (result < 0)
    return -1;

  stream.read (str, FixedFieldBufferHeaderSize);
  if (!stream.good ())
    return -1;

  if (strncmp (str, FixedFieldBufferHeaderStr, FixedFieldBufferHeaderSize)
      != 0)
    return -1;

  stream.read ((char *)&numFields, sizeof (numFields));
  if (!stream)
    return -1;

  fieldSize = new int[numFields];
  for (int i = 0; i < numFields; i++)
    {
      stream.read ((char *)&fieldSize[i], sizeof (fieldSize[i]));
    }

  if (_initialized)
    {
      if (numFields != _numFields)
        return -1;
      for (int j = 0; j < _numFields; j++)
        {
          if (fieldSize[j] != _fieldSize[j])
            return -1;
        }
      return stream.tellg ();
    }

  Init (numFields, fieldSize);
  return stream.tellg ();
}

int
FixedFieldBuffer::WriteHeader (ostream &stream) const
{
  int result;

  if (!_initialized)
    return -1;
  result = FixedLengthBuffer::WriteHeader (stream);
  if (!result)
    return -1;

  stream.write (FixedFieldBufferHeaderStr, FixedFieldBufferHeaderSize);
  if (!stream.good ())
    return -1;

  stream.write ((char *)&_numFields, sizeof (_numFields));
  for (int i = 0; i < _numFields; i++)
    {
      stream.write ((char *)&_fieldSize[i], sizeof (_fieldSize[i]));
    }
  if (!stream)
    return -1;
  return stream.tellp ();
}

int
FixedFieldBuffer::Pack (const void *field, int size)
{
  if (_nextField == _numFields || !_packing)
    return -1;

  int start = _nextByte;
  int packSize = _fieldSize[_nextField];
  if (size != -1 && packSize != size)
    return -1;

  memcpy (&_buffer[start], field, packSize);
  _nextByte += packSize;
  _nextField++;

  if (_nextField == _numFields)
    {
      _packing = false;
      _nextField = _nextByte = 0;
    }

  return packSize;
}

int
FixedFieldBuffer::Unpack (void *field, int maxBytes)
{
  _packing = false;
  if (_nextField == _numFields)
    return -1;

  int start = _nextByte;
  int packSize = _fieldSize[_nextField];

  memcpy (field, &_buffer[start], packSize);
  _nextByte += packSize;
  _nextField++;
  if (_nextField == _numFields)
    Clear ();
  return packSize;
}

void
FixedFieldBuffer::Print (ostream &stream) const
{
  FixedLengthBuffer::Print (stream);
  stream << endl;
  stream << "\t max fields" << _maxFields << " and actual " << _numFields
         << endl;
  for (int i = 0; i < _numFields; i++)
    stream << "\tfield " << i << " size " << _fieldSize[i] << endl;
  _buffer[_bufferSize] = 0;
  stream << "NextByte " << _nextByte << endl;
  stream << "Buffer " << _buffer << endl;
}

int
FixedFieldBuffer::Init (int maxFields)
{
  Clear ();
  if (maxFields < 0)
    maxFields = 0;
  _maxFields = maxFields;
  _fieldSize = new int[_maxFields];
  _bufferSize = 0;
  _numFields = 0;
  return 1;
}

int
FixedFieldBuffer::Init (int numFields, int *fieldSize)
{
  _initialized = true;
  Init (numFields);

  for (int j = 0; j < numFields; j++)
    AddField (fieldSize[j]);

  return true;
}