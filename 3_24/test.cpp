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
	if(v1.end() - v1.begin() <=1)  
    {  
    cout<<"too few elements in the vector\n";      
    }
	cout<<"the sum of next data is "<<endl;
	for(auto it=v1.begin();it!=v1.end()-1;++it){
		cout<<*it+*(it+1)<<'\t';
	}
	return 0;
}