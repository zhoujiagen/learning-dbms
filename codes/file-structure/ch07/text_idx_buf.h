#ifndef CH07_TEXT_IDX_BUF
#define CH07_TEXT_IDX_BUF

#include "buf.h"
#include "text_idx.h"
#include <streambuf>

using namespace std;

class TextIndexBuffer : public FixedFieldBuffer
{
public:
  TextIndexBuffer (int keySize, int maxKeys = 100, int extraFields = 0,
                   int extraSize = 0);
  int Pack (const TextIndex &);
  int Unpack (TextIndex &);
  void Print (ostream &) const;

protected:
  int _maxKeys;
  int _keySize;
  char *_dummy;
};

#endif /* CH07_TEXT_IDX_BUF */
