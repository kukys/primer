#include<vector>
#include<iostream>
#include<string>
using std::string;
using std::vector;
using std::cin;
using std::cout;
  int main()
  {
    vector<string> vec;
    string s;
    while(cin>>s)
    {
      vec.push_back(s);
    }
    cout<<vec.size()<<" ----"<<vec.capacity();
  }