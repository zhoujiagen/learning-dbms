#ifndef LIB_REC_FILE
#define LIB_REC_FILE

#include "buf_file.h"

template <class RecType> // Pack(IOBuffer &), Unpack(IOBuffer &)
class RecordFile : public BufferFile
{
public:
  int Read (RecType &record, int recaddr = -1);
  int Write (const RecType &record, int recaddr = -1);
  int Append (const RecType &record);
  RecordFile (IOBuffer &buffer) : BufferFile (buffer) {}
};

template <class RecType>
int
RecordFile<RecType>::Read (RecType &record, int recaddr)
{
  int readAddr, result;
  readAddr = BufferFile::Read (recaddr);
  if (readAddr == -1)
    return -1;

  result = record.Unpack (_buffer);
  if (!result)
    return -1;

  return readAddr;
}

template <class RecType>
int
RecordFile<RecType>::Write (const RecType &record, int recaddr)
{
  int result;

  result = record.Pack (_buffer);
  if (!result)
    return -1;

  return BufferFile::Write (recaddr);
}

template <class RecType>
int
RecordFile<RecType>::Append (const RecType &record)
{
  int result;

  result = record.Pack (_buffer);
  if (!result)
    return -1;

  return BufferFile::Append ();
}

#endif /* LIB_REC_FILE */
