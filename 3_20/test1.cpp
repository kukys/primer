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
	if(v1.size()%2==0){
	for(auto xx=0;xx!=v1.size()/2;++xx){
		cout<<v1[xx]+v1[v1.size()-xx-1]<<'\t';
	}
}
else{
		for(auto xx=0;xx!=v1.size()/2;++xx){
		cout<<v1[xx]+v1[v1.size()-xx-1]<<'\t';
	}
	cout<<endl;
	cout<<"the mid numeber is"<<v1[v1.size()/2];
}
	return 0;
}