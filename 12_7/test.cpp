/*
把12_6的内置指针换成shared_ptr
*/
#include<vector>
#include<iostream>
#include<memory>
using namespace std;
void add (std::shared_ptr<vector<int>>s);
void print(std::shared_ptr<vector<int>>s);

int main()
{
  auto vec = make_shared<vector<int>>();
  add(vec);
  print(vec);
  return 0;
}
void add (std::shared_ptr<vector<int>>s)
{
  int i;
  while(cin>>i)
  {
    s->push_back(i);
  }
}
void print(std::shared_ptr<vector<int>>s)
{
  for(const auto &c:*s)
    {
      cout<<c<<" ";
    }  
}

