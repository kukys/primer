#include<iostream>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main()
{
	int a,b;
	vector<int>v2={1,2,2,3};
  vector<int>v1={1,2,2,2,2};
  vector<int>q;
  if(v1.size()>v2.size())
  	{
  		vector<int> q(v1);
  		vector<int> v1(v2);
  		vector<int> v2(q);
  		
  	}
  bool s;
  for(decltype(v1.size()) i=0;i!=v1.size();i++)
  {
  	if(v1[i]==v2[i])
  		{
  			s=true;
  		}
  		else
  			{
  			s=false;
  			break;
  		}
  }
 if(s==true)
  	{
  		cout<<"yes";
  	}
  if(s==false)
  		{
  			cout<<"No";
  		}
  return 0;
}