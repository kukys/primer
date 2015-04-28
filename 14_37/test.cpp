#include "test.h"
#include <iostream>
#include <algorithm>
#include <vector>
//using std::vector;
using std::cout;
int main(int argc, char const *argv[])
{
  std::vector<int> vec ={4,4,4,4,4,9,9,9,9,9};
  for(auto v:vec)
  {
    cout<<v<<"-";
  }
  cout<<std::endl;
  std::for_each(vec.begin(),vec.end(),Equal(4,9));
  for(auto v:vec)
  {
    cout<<v<<"-";
  }
}

