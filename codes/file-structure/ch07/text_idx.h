#ifndef CH07_TEXT_IDX
#define CH07_TEXT_IDX

#include <iostream>

using namespace std;

class TextIndexBuffer; // forward declaration

class TextIndex
{
public:
  TextIndex (int maxKeys = 100, bool unique = true);
  ~TextIndex ();
  int Insert (const char *key, int recaddr);
  int Remove (const char *key);
  int Search (const char *key) const;
  void Print (ostream &) const;

protected:
  int _maxKeys;
  int _numKeys;
  char **_keys;
  int *_recAddrs;
  int Find (const char *key) const;
  int Init (int maxKeys, bool unique);
  bool _unique;
  friend class TextIndexBuffer;
};

#endif /* CH07_TEXT_IDX */
