#include<vector>
#include<iostream>
using std::vector;
using std::cout;
using std::endl;
  int main()
  {
    vector<int> vec={0,1,2,3,4,5,6,7,8,9};
    vector<int>::const_iterator iter = vec.cend();
    while(iter!=vec.cbegin())
    {
      --iter;
      cout<<*iter<<endl;
    }
  }