/*
编写一个递归函数,输出vector对象的内容
*/
#include<iostream>
#include<string>
#include<vector>
using std::string;
using std::cout;
using std::cin;
using std::vector;
void vector_print(const vector<int> &s)
{
	static vector<int>::const_iterator it=s.begin();
	cout<<*it;
	++it;
	if(it!=s.end())
		{
			vector_print(s);
		}
		
}
int main()
{
	vector<int>v1;
	int a;
while(cin>>a)
{
	v1.push_back(a);
}
	vector_print(v1);
	return 0;
}