#include "buf_file.h"
#include "buf.h"
#include <fstream>
#include <iostream>

using namespace std;

BufferFile::BufferFile (IOBuffer &from) : _buffer (from) {}

int
BufferFile::Open (const char *filename, int mode)
{
  if (mode & ios::trunc) // noreplace
    return false;

  _file.open (filename, mode | ios::in | ios::binary); // nocreate
  if (!_file.good ())
    return false;

  _file.seekg (0, ios::beg);
  _file.seekp (0, ios::beg);
  _headerSize = ReadHeader ();
  if (!_headerSize)
    return false;

  _file.seekp (_headerSize, ios::beg);
  _file.seekp (_headerSize, ios::beg);
  return _file.good ();
}

int
BufferFile::Create (const char *filename, int mode)
{
  if (!(mode & ios::out))
    return false;
  _file.open (filename, mode | ios::out | ios::binary); // noreplace
  if (!_file.good ())
    {
      _file.close ();
      return false;
    }
  _headerSize = WriteHeader ();
  return _headerSize != 0;
}

int
BufferFile::Close ()
{
  _file.close ();
  return true;
}

int
BufferFile::Rewind ()
{
  _file.seekg (_headerSize, ios::beg);
  _file.seekp (_headerSize, ios::beg);
  return 1;
}

int
BufferFile::Read (int recaddr)
{
  if (recaddr == -1)
    return _buffer.Read (_file);
  else
    return _buffer.DRead (_file, recaddr);
}

int
BufferFile::Write (int recaddr)
{
  if (recaddr == -1)
    return _buffer.Write (_file);
  else
    return _buffer.DWrite (_file, recaddr);
}

int
BufferFile::Append ()
{
  _file.seekp (0, ios::end);
  return _buffer.Write (_file);
}

IOBuffer &
BufferFile::GetBuffer ()
{
  return _buffer;
}

int
BufferFile::ReadHeader ()
{
  return _buffer.ReadHeader (_file);
}

int
BufferFile::WriteHeader ()
{
  return _buffer.WriteHeader (_file);
}