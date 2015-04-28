#include "test.h"
#include <vector>
using std::vector;
int main(int argc, char const *argv[])
{
  PrintString printer;
  vector<string> vec;
  for (int i = 0; i < 5; ++i)
  {
      vec.push_back(printer());
  }
  for(auto c:vec)
  {
    cout<<c<<std::endl;
  }
  return 0;
}
