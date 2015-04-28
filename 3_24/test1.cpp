#include<iostream>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(){
	int i=0;
	vector<int > v1;
	while(cin>>i){
		v1.push_back(i);
	}
	if(v1.empty()){
			cout<<"No member";
		}
	cout<<"the sum of next data is "<<endl;
	auto beg=v1.begin(),end=v1.end();
	auto mid=v1.begin()+(end-beg)/2;
	if(v1.size()%2==0){
	for(;beg!=mid;++beg){
		cout<<*beg+*(v1.end() - beg -1 + v1.begin())<<'\t';
	}
}
else{
	for(;beg!=mid;++beg){
		cout<<*beg+*(v1.end() - beg -1 + v1.begin())<<'\t';
	}
	cout<<endl;
	cout<<"the mid numeber is"<<*mid;
}
	return 0;
}