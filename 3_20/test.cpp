#include<iostream>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main()
{
	int i=0;
	vector<int > v1;
	while(cin>>i)
	{
		v1.push_back(i);
	}
	if(v1.empty())
		{
			cout<<"No member";
		}
	cout<<"the sum of next data is "<<endl;
	for(auto xx=0;xx!=v1.size()-1;++xx)
	{
		cout<<v1[xx]+v1[xx+1]<<'\t';
	}
	if(v1.size()==1)
	{
		cout<<v1[0];
	}
	return 0;
}