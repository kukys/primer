#include<iostream>
using namespace std;
int main()
{
  char *c= new char[10]();
  cin.get(c,10);
  cout<<c;
  delete[]c;
}
//����������ȣ�ֻ�����ָ�����ȵ��ַ���