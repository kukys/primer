#include<iostream>
#include<vector>
#include <typeinfo> 
using std::vector;
using std::cin;
using std::cout;
using std::endl;
	int Operation(const int a,const int b);
	typedef decltype(Operation) op;//不能用op 初始化NumAdd因为是一个指针
	
	int NumAdd(const int a,const int b)
	{
		return a+b;
	}
	int NumSub(const int a,const int b)
	{
		return a-b;
	}
	int NumMul(const int a,const int b)
	{
		return a*b;
	}
	int NumDiv(const int a,const int b)
	{
		return a/b;
	}
	 vector<op*>v1{NumAdd,NumSub,NumMul,NumDiv};
int main()
{
	vector<op*>::iterator it=v1.begin();
	do
		{
			cout<<(*it)(2,2);
			cout<<endl;
			++it;
		}while(it!=v1.end());
}
	