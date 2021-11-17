#include "person.h"
#include <string>
int
main (int argc, char const *argv[])
{
  Person p;
  strcpy (p.FirstName, "hello");
  Person *p_ptr = new Person;
  strcpy (p_ptr->FirstName, "there");

  return 0;
}
