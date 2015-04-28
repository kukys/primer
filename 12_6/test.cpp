/*
编写函数，返回一个动态分配的int的vector。将此vector传递给另一个函数，这个函数读取标准输入
将读入的的值保存在vector中，再将vector传递给另一个函数,打印读入的值.记得delete vector
*/
#include<vector>
#include<iostream>
using namespace std;

void add(vector<int>*s)
{
  int i;
  while(cin>>i)
  {
    s->push_back(i);
  }
}

void print(vector<int>*s)
{
  for(const auto &c:*s)
    {
      cout<<c<<" ";
    }  
}
int main()
{
  vector<int> *vec = new vector<int>;
  add(vec);
  print(vec);
  delete vec;
}