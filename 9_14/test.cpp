#include<list>
#include<vector>
#include<string>
#include<iostream>
using std::list;
using std::vector;
using std::string;
  using std::endl;
    using std::cout;
  int main()
  {
    list<const char *>v1(10,"HI");
    vector<string>v2;
    v2.assign(v1.cbegin(),v1.cend());
    for(auto c:v2)
      {
        cout<<c<<endl;
      }
  }