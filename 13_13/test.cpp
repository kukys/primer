/*
*给添加拷贝运算符和析构函数，并编写一个程序以不同的方式使用X的对象：将它们作为非引用
和引用参数的传递;动态分配他们;将它们存放于容器中;诸如此类.观察程序的输出,知道理解了什么时候
会使用拷贝构造控制成员,以及为什么使用它们.记住编译器可以略过对拷贝构造函数的调用.
*/
#include"test.h"
#include<memory>
#include<vector>
using std::shared_ptr;
  using std::make_shared;
    using std::vector;
int main()
{
  /*X	t(5);
  X	c(t);
  c=t;*/
  X t;
  X c=t;//只进行拷贝；不进行赋值
  /*X *p = new X();
  auto p2 = make_shared<X>();
  X item(*p);                         //拷贝构造函数将*p拷贝到itrm中
  vector<X>vec;
  vec.push_back(*p2);      //拷贝p2指向的对象
  delete p;*/
  return 0;
}