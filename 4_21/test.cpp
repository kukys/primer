#include<iostream>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main()
{
	int i;
	vector<int> v;
	while(cin>>i)
	{
		v.push_back(i);
	}
	for(auto a:v)           //条件语句，判断那个是奇数
		{
			cout<<a;
			cout<<((a%2==0)?"是偶数" :"是奇数" );
	    cout<<endl;
		}
		cout<<endl;
		for(auto &c:v){            //使奇数翻倍
				if(c%2!=0)
					{
						c=c*c;
					}
			}
    for(auto c:v){
			   cout<<c<<" ";
		   }
return 0;	
}