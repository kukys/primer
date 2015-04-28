#include<iostream>
#include<string>
using std::string;
using std::cout;
	
int main(){
string s ="word";
string i=((s+s[s.size()-1]) == 's' ? " " : "s");
cout<<i;
}