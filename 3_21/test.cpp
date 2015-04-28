#include<iostream>
#include<vector>
#include<string>
using std::cout;
using std::vector;
using std::endl;
using std::string;
int main()
{
	vector<int> v1 (10,42);
  for(auto it = v1.cbegin();it!=v1.cend();++it)
  {
  	cout<<*it<<'\t';
  }
  cout<<endl;
  cout<<v1.size()<<endl;
  vector<string> v2{10,"hi"};
  for(auto it=v2.cbegin();it!=v2.cend();++it)
  {
  	cout<<*it<<'\t';
  }
  cout<<endl<<v2.size();
  return 0;
}