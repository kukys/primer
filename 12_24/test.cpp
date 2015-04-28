#include<iostream>
using namespace std;
int main()
{
  char *c= new char[10]();
  cin.get(c,10);
  cout<<c;
  delete[]c;
}
//如果超过长度，只会输出指定长度的字符串