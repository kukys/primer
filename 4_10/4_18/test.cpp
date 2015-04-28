#include<iostream>
#include<vector>
using std::cin;
using std::cout;
using std::vector;
	using std::endl;
int main(){
	int i=0;
	vector<int> v;
	while(cin>>i){
		v.push_back(i);
	}
	auto pbeg=v.begin();
	while(pbeg!=v.end()&&*pbeg>=0){
	 cout<<*++pbeg<<endl;
	}
}