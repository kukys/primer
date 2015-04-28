#include<iostream>
using std::cout;
  using std::endl;
    int main()
    {
      int a=5;
      auto f =[a]( int b){return a+b;};
      cout<<f(1);
    }