#ifndef LIB_BUF_FILE
#define LIB_BUF_FILE

#include "buf.h"
#include <fstream>

using namespace std;

//! Class to represent buffered file operation
class BufferFile
{
public:
  BufferFile (IOBuffer &);

  int Open (const char *filename, int mode);   //!< open an existing file
  int Create (const char *filename, int mode); //!< create a new file
  int Close ();
  int Rewind (); //!< reset to the first data record

  // input and output operations

  int Read (int recaddr
            = -1); //!< read a record into the buufer, return the record
                   //!< address, if recaddr == -1, read the next record
  int Write (int recaddr = -1); //!< write the buffer contents
  int Append ();          //!< write the current buffer at the end of file
  IOBuffer &GetBuffer (); //!< access to IOBuffer

protected:
  IOBuffer &_buffer;
  fstream _file;
  int _headerSize; //!< size of header
  int ReadHeader ();
  int WriteHeader ();
};

template <class RecType> class RecordFile : public BufferFile
{
public:
  int Read (RecType &record, int recaddr = -1);
  int Write (const RecType &record, int recaddr = -1);
  int Append (const RecType &record, int recaddr = -1);
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
RecordFile<RecType>::Append (const RecType &record, int recaddr)
{
  int result;

  result = record.Pack (_buffer);
  if (!result)
    return -1;
  return BufferFile::Append ();
}

#endif /* LIB_BUF_FILE */
