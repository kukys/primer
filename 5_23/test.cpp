#include<iostream>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;
int main()
{
int a,b;
while(cin>>a>>b)
{
	try{
		if(b==0)
			throw runtime_error("����Ϊ��");
		cout<<"���Ϊ"<<a/b<<endl;
	}catch(runtime_error){
		cout<<"��������Ϊ��";
		cout<<"Try Again��Enter yes or no"<<endl;
		char c;
		cin>>c;
		if(!cin||c=='n')
			break;
	}
}
}
