/*
��д����������һ����̬�����int��vector������vector���ݸ���һ�����������������ȡ��׼����
������ĵ�ֵ������vector�У��ٽ�vector���ݸ���һ������,��ӡ�����ֵ.�ǵ�delete vector
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