/*
如果试图拷贝或赋值unique_ptr编译器并不总是能给出易于理解的错误信息
编写包含这种错误的程序，观察编译器的错误
*/
#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;
int main()
{
  unique_ptr<string> p1(new string("hello"));
  //unique_ptr<string> p2(p1);
  /*
error: use of deleted function 'std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) 
[with _Tp = std::basic_string<char>; _Dp= std::default_delete<std::basic_string<char> >]'unique_ptr<string> p2(p1);
   */
   unique_ptr<string> p3;
   p3=p1;
   /*
 error: use of deleted function 'std::unique_ptr<_Tp, _Dp>& std::unique_ptr<_Tp, _Dp>::operator=
 (const std::unique_ptr<_Tp, _Dp>&) [with _Tp = std::basic_string<char>; 
 _Dp = std::default_delete<std::basic_string<char> >]'
   */
}