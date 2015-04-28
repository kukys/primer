#include<iostream>
#include<vector>
using std::cout;
using std::endl;
using std::cin;
using std::vector;
int main()
{
	int i=0;
	vector<int > v1;
	while(cin>>i)
	{
		v1.push_back(i);
	}
	if(v1.size()<=10)
	{
	for(auto it=v1.begin();it!=v1.end();++it)
	 {
		*it *=2;
	 }
	 for(auto c:v1)
	 	{
	 		cout<<c<<'\t';
	 	} 
  }
  else 
	{
 std::cerr<<"over";
 return -1;
  }
}