#include<iostream>
using std::cout;
  using std::endl;
    int main()
    {
      //声明的 lambda 表达式将返回两个整数的总和并使用参数 5 和 4 立即调用该表达式：
      auto f = [](const int &a,const int &b){return  a+b;}(5,4);
      cout<<f;
      cout<<endl;
      // lambda 表达式作为参数传递
      auto b = [](const int &a,const int &b){return  a+b;};
      cout<<b(1,2);
      cout<<endl;
      auto s =[] {return 42;}();
      cout<<s;
    } 