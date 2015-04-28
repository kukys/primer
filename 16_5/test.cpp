#include <iostream>
#include <string>
using namespace std;
template <typename T>
void  print(const T& t)
{
  for(auto elem :t)
  {
    cout<<elem<<'\t';
  }
  cout<<endl;
}
int main(int argc, char const *argv[])
{
  int k[10]={0,1,2,3,454,56};
  print(k);
  string k1[5]={"a","b","c","d","e"};
  print(k1);
  return 0;
}
