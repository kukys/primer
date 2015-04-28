#include<iostream>
using std::cout;
using std::cin;
using std::endl;
int fact(int val)
{
	if(val>=0)
		{
			return val;
		}
		else
			{
				return -val;
			}
}
int main()
{
	int a;
	while(cin>>a)
	{
		cout<<a<<"的绝对值是"
		    << fact(a) <<endl;
	}
}
