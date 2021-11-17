#include "text_idx_buf.h"
#include "buf.h"
#include "text_idx.h"

TextIndexBuffer::TextIndexBuffer (int keySize, int maxKeys, int extraFields,
                                  int extraSpace)
    : FixedFieldBuffer (1 + 2 * maxKeys + extraFields,
                        sizeof (int) + maxKeys * keySize
                            + maxKeys * sizeof (int) + extraSpace)
{
  _maxKeys = maxKeys;
  _keySize = keySize;
  AddField (sizeof (int));
  for (int i = 0; i < _maxKeys; i++)
    {
      AddField (_keySize);
      AddField (sizeof (int));
    }
  _dummy = new char[_keySize + 1];
}

int
TextIndexBuffer::Pack (const TextIndex &index)
{
  int result;
  Clear ();
  result = FixedFieldBuffer::Pack (&index._numKeys);
  for (int i = 0; i < index._numKeys; i++)
    {
      result = result && FixedFieldBuffer::Pack (index._keys[i]);
      result = result && FixedFieldBuffer::Pack (&index._recAddrs[i]);
    }

  for (int j = 0; j < index._maxKeys - index._numKeys; j++)
    {
      result = result && FixedFieldBuffer::Pack (_dummy);
      result = result && FixedFieldBuffer::Pack (_dummy);
    }
  return result;
}

int
TextIndexBuffer::Unpack (TextIndex &index)
{
  int result;
  result = FixedFieldBuffer::Unpack (&index._numKeys);
  for (int i = 0; i < index._numKeys; i++)
    {
      index._keys[i] = new char[_keySize];
      result = result && FixedFieldBuffer::Unpack (index._keys[i]);
      result = result && FixedFieldBuffer::Unpack (&index._recAddrs[i]);
    }
  for (int j = 0; j < index._maxKeys - index._numKeys; j++)
    {
      result = result && FixedFieldBuffer::Unpack (_dummy);
      result = result && FixedFieldBuffer::Unpack (_dummy);
    }
  return result;
}

void
TextIndexBuffer::Print (ostream &stream) const
{
  stream << "TextIndexBuffer: _keySize=" << _keySize
         << ", _maxKeys=" << _maxKeys << endl;
  FixedFieldBuffer::Print (stream);
}