#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace::std;
int main(int argc, char const *argv[])
{
  int num;
  cout<<"why"<<endl;
  cin>>num;
  string ret ="Yes";
  modulus<int> m;
  vector<int>vec ={2,21,3,12,12};
  for(const auto &i:vec)
  {
    if(m(i,num))
    {
      ret="No";
      break;
    }
  }
  cout<<ret<<endl;
  return 0;
}
