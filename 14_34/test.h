#ifndef TEST_H
#define TEST_H
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
class Check
{
public:
  Check()=default;
  void operator()(const int &a,const int &b,const int &c)
  {
    if(a>=0)
    {
      cout<<"b"<<endl;
    }
    else
      cout<<"c"<<endl;
  }
private:
  int a,b,c;
};
#endif//TEST_H
