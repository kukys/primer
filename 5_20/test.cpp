#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
int main()
{
	int a;
	string s1,q,s2;
  cin>>s1;
  q=s1;
  while(cin>>s2)
  {
  	if(islower(s2[0]))//
  		{
  			continue;     //��һ����5_21�Ĵ���
  		}               //
  	if(q==s2)
  		{
  			a=1;
  			break;
  		
  		}
  		if(q!=s2)
  			{
  				q=s2;
  				a=0;
  			}
  }
  if(a==0)
  	{
  		cout<<"û�������ظ��ĵ���";
  	}
  	else
  		{
  			cout<<q<<"��������";
  		}
 return 0;
}