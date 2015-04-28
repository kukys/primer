#include<iostream>
#include<vector>
#include<string>
#include<cctype>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
int main()
{
	string s;
  vector<string> v3;
  while(cin>>s)
  {
  	v3.push_back(s);
  }
for(auto c:v3)
	{
  for(auto &ch:c)
    {
  	  ch=toupper(ch);
    }
 	cout<<c<<endl;
  }
	return 0;
}
