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
  			continue;     //这一段是5_21的代码
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
  		cout<<"没有连续重复的单词";
  	}
  	else
  		{
  			cout<<q<<"连续出现";
  		}
 return 0;
}