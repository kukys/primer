#include<iostream>
using namespace std;
int fact(int val)
{
	int ret=1;
	while(val>1)
	    ret*=val--;
	    return ret;
}
int main()
{
	cout<<"please input a numbler"<<endl;
	int a;
	cin>>a;
	int j=fact(a);
	cout<<j;
	return 0;
}