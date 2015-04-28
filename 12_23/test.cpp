#include <iostream>
#include <string>
#include <string.h>
int main()
{
  char *c = new char[256]();
  strcat(c,"hello");
  strcat(c," world");
  std::cout<<c;
    delete [] c;
}
