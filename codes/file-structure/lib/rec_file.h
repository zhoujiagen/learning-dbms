#ifndef LIB_REC_FILE
#define LIB_REC_FILE

#include "buf_file.h"

template <class RecType> //
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
Read (RecType &record, int recaddr = -1)
{
  int writeAddr, result;
  writeAddr = BufferFile::Read (recaddr);
  if (!writeAddr)
    return -1;

  result = record.Unpack (_buffer);
  if (!result)
    return -1;

  return writeAddr;
}

template <class RecType>
int
Write (const RecType &record, int recaddr = -1)
{
  int result;

  result = record.Pack (_buffer);
  if (!result)
    return -1;

  return BufferFile::Write (recaddr);
}

template <class RecType>
int
Append (const RecType &record)
{
  int result;

  result = record.Pack (_buffer);
  if (!result)
    return -1;

  return BufferFile::Append ();
}

#endif /* LIB_REC_FILE */
