#include"test.h"
#include<iostream>
using std::cout;
using std::endl;
   /*void f (numbered s)//将对象作为实参传递给一个非引用类型的形参,会执行拷贝初始化
  {
    cout<<s.mysn<<endl;
  }*/

  void f(const numbered &s)//当参数是 const numbered&时，不会拷贝函数，执行默认初始化函数
  {
     cout<<s.mysn<<endl;
  }
  int main()
  {
    numbered a;//默认初始化
    numbered b=a;//拷贝初始化(如果系统没有拷贝构造函数，会初始化一个)
   numbered c=b;//拷贝初始化(如果系统没有拷贝构造函数，会初始化一个)
    f(a);
    f(b);
    f(c);
    return 0;
  }