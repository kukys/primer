#include<iostream>
using std::cout;
  using std::endl;
    int main()
    {
      //������ lambda ����ʽ�����������������ܺͲ�ʹ�ò��� 5 �� 4 �������øñ���ʽ��
      auto f = [](const int &a,const int &b){return  a+b;}(5,4);
      cout<<f;
      cout<<endl;
      // lambda ����ʽ��Ϊ��������
      auto b = [](const int &a,const int &b){return  a+b;};
      cout<<b(1,2);
      cout<<endl;
      auto s =[] {return 42;}();
      cout<<s;
    } 