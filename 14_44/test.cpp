#include <functional>
#include <iostream>
#include <map>
#include <string>
using namespace::std;
int add(int i,int j)
{
  return i+j;
}
auto mod=[](const int i,const int j){return i%j;};

struct divide
{
  int operator()(int denominator,int divisor)
  {
    if(divisor!=0)
    {
      return denominator/divisor;
    }
    else
      cerr<<"divisor is zero"<<endl;
    return -1;
  }
};
void print(string c,int i,int j)
{
  map<string,function<int(int,int)>>binops={
  {"+",add},
  {"-",minus<int>()},
  {"*",[](int i,int j){return i*j;}},
  {"/",divide()},
  {"%",mod}};
  cout<<binops[c](i,j)<<endl;
}
int main(int argc, char const *argv[])
{
    string c;
    int num1,num2;
    while(cin>>num1>>c>>num2)
  {
   print(c,num1,num2);
  }

  return 0;
}
