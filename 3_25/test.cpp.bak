#include<iostream>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main()
{
vector<unsigned> scores(11,0);
auto it=scores.begin();
unsigned grade;
while(cin>>grade){
     if(grade<=100){
     	auto g=grade/10;
     	*(it+g)=*(it+g)+1;
     }
  }
  for(;it!=scores.end();it++)
  {
cout<<*it<<" ";
}
}