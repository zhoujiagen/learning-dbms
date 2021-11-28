#include "btree.h"
#include "log.h"

using namespace std;

const char *keys = "CSDTAMPIBWNGURKEHOLJYQZFXV";
const int BTreeSize = 4;

int
main (int argc, char const *argv[])
{
  // init_log ();

  int result, i;
  BTree<char> btree (BTreeSize, sizeof (char), true);
  result = btree.Create ("btree.fsdat",
                         ios::in | ios::out | ios::binary | ios::trunc);

  for (i = 0; i < 26; i++) // DEBUG: 5
    {
      cout << endl << "Insert " << keys[i] << endl;
      result = btree.Insert (keys[i], i);
      btree.Print (cout);
    }

  btree.Search (1, 1);

  return 0;
}
