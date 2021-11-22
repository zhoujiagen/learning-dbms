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

#endif /* LIB_BUF_FILE */
