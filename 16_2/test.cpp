#include  <iostream>
#include <string>
using std::string;
template <typename T>
int compare(const T& v1,const T& v2)
{
  if(v1<v2) return -1;
  if(v2<v1) return 1;
    return 0;
}
int main(int argc, char const *argv[])
{
  std::cout<<compare(1,2)<<std::endl;
  string s1="A",s2="B";
  std::cout<<compare("s1","s2")<<std::endl;
  return 0;
}
