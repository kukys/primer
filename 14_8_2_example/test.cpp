#include <functional>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::multiplies;
using std::negate;
int main(int argc, char const *argv[])
{
  multiplies<int> intAdd;     //可执行int加法函数对象
  negate<int> intNegate;//可执行int值取反的函数对象

  int sum=intAdd(10,20);

  //sum=intNegate(intAdd(10,20));
  cout<<sum<<endl;
  return 0;
}
