/*
*��д���򣬶���һ�����߼�����Ʒ��multimap��ʹ�� find��multimap�в���һ��Ԫ��
*��ʹ��eraseɾ������ȷ����ĳ��� ��Ԫ�ز���map��Ҳ��������.
*/
#include<map>
#include<iostream>
using namespace std;
int main()
{
  multimap<string,string>authors;
  string Name,Bookname;
  while(cin>>Name>>Bookname)
  {
    authors.emplace(Name,Bookname);
  }
  string search_item("yang");
  auto iter = authors.find(search_item);
  if(iter==authors.end())
    {
      cout<<"û���������";
    }
    else
      {
  auto cnt=authors.erase(iter);
  for(auto c:authors)
    {
      cout<<c.first<<" "<<c.second<<endl;//Ĭ�ϵ�����ʽ���ǰ��ֵ���..//11_32
    }
  }
}