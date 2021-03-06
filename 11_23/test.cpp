/*
11.2.1节练习中的map以孩子的姓为关键字，保存他们的名的vector，用multimap重写这个程序.
*/
#include<map>
#include<vector>
#include<iostream>
using namespace std;
int main()
{
  multimap<string,string>family;//由于multimap允许关键字重复，所以可以不用vector;
  string Surname,ChilderName;
  while(cin>>Surname>>ChilderName)
  {
    family.emplace(Surname,ChilderName);//将参数传递给元素类型的构造函数
  }
  for(auto f:family)
    {
      cout<<f.first<<"-"<<f.second<<endl;
    }
}