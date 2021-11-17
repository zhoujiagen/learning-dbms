#ifndef CH07_TEXT_IDX_FILE
#define CH07_TEXT_IDX_FILE

#include "buf.h"
#include "buf_file.h"
#include "rec_file.h"
#include "text_idx_buf.h"
#include <iostream>
#include <string>
#include <strstream>

using namespace std;

//! template class to support indexed read and write of records
//! using RecordFile, BufferFile, TextIndex and TextIndexBuffer
template <class RecType> //
class TextIndexedFile
{
public:
  int Read (RecType &record);            //<! read next record
  int Read (char *key, RecType &record); //<! read by key
  int Append (const RecType &record);
  int Update (char *oldKey, const RecType &record);
  int Create (char *fileName, int mode = ios::in | ios::out);
  int Open (char *fileName, int mode = ios::in | ios::out);
  int Close ();
  TextIndexedFile (IOBuffer &buffer, int keySize, int maxKeys = 100);
  ~TextIndexedFile (); //<! close and delete

protected:
  TextIndex _index;
  BufferFile _indexFile;
  TextIndexBuffer _indexBuffer;
  RecordFile<RecType> _dataFile;
  char *_fileName; //!< base file name
  int SetFileName (char *fileName, char *&dataFileName, char *&indexFileName);
};

template <class RecType>
int
TextIndexedFile<RecType>::Read (RecType &record)
{
  return _dataFile.Read (record, -1);
}

template <class RecType>
int
TextIndexedFile<RecType>::Read (char *key, RecType &record)
{
  int ref = _index.Search (key);
  if (ref < 0)
    return -1;

  return _dataFile.Read (record, ref);
}

template <class RecType>
int
TextIndexedFile<RecType>::Append (const RecType &record)
{
  char *key = record.Key ();
  int ref = _index.Search (key);
  if (ref = -1)
    return -1;

  ref = _dataFile.Append (record);
  return _index.Insert (key, ref);
}

template <class RecType>
int
TextIndexedFile<RecType>::Update (char *oldKey, const RecType &record)
{
  // TODO
  return -1;
}

template <class RecType>
int
SetFileName (char *fileName, char *&dataFileName, char *&indexFileName)
{
  if (_fileName != 0)
    return 0;

  _fileName = strdup (fileName);
  ostrstream dataName, indexName;
  dataName << _fileName << ".fsdat" << ends;
  indexName << _fileName << ".fsidx" << ends;
  dataFileName = strdup (dataName.str ());
  indexFileName = strdup (indexName.str ());
  return 1;
}

template <class RecType>
int
TextIndexedFile<RecType>::Create (char *fileName, int mode)
{
  int result;
  char *dataFileName, *indexFileName;

  result = SetFileName (fileName, dataFileName, indexFileName);
  if (result == -1)
    return 0;
  result = _dataFile.Create (dataFileName, mode);
  if (!result)
    {
      _fileName = NULL;
      return 0;
    }

  result = _indexFile.Create (indexFileName, ios::out | ios::in);
  if (!result)
    {
      _dataFile.Close ();
      _fileName = NULL;
      return 0;
    }

  return 1;
}

template <class RecType>
int
TextIndexedFile<RecType>::Open (char *fileName, int mode)
{
  int result;
  char *dataFileName, *indexFileName;

  result = SetFileName (fileName, dataFileName, indexFileName);
  if (!result)
    return 0;

  result = _dataFile.Open (dataFileName, mode);
  if (!result)
    {
      _fileName = NULL;
      return 0;
    }

  result = _indexFile.Open (indexFileName, ios::out);
  if (!result)
    {
      _dataFile.Close ();
      _fileName = NULL;
      return 0;
    }

  // read index into memory
  result = _indexFile.Read ();
  if (result != -1)
    {
      result = _indexBuffer.Unpack (_index);
      if (result != -1)
        return 1;
    }

  _dataFile.Close ();
  _indexFile.Close ();
  _fileName = NULL;
  return 0;
}

template <class RecType>
int
TextIndexedFile<RecType>::Close ()
{
  int result;

  if (_fileName == NULL)
    return 0;

  _dataFile.Close ();
  _indexFile.Rewind ();
  _indexBuffer.Pack (_index);
  result = _indexFile.Write ();
  cout << "result of index write: " << result << endl;
  _indexFile.Close ();
  _fileName = NULL;
  return 1;
}

template <class RecType>
TextIndexedFile<RecType>::TextIndexedFile (IOBuffer &buffer, int keySize,
                                           int maxKeys = 100)
    : _dataFile (buffer), _index (maxKeys), _indexFile (_indexBuffer),
      _indexBuffer (keySize, maxKeys)
{
  _fileName = NULL;
}

template <class RecType> TextIndexedFile<RecType>::~TextIndexedFile ()
{
  CLose ();
}

#endif /* CH07_TEXT_IDX_FILE */
