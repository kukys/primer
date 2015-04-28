#include"E:\MinGW\project\test\Sales_item.h"
#include<set>
bool pcompareIsbn(const Sales_item &ihs,const Sales_item &rhs)
{
  return ihs.isbn()<rhs.isbn();
}
int main()
{
  /*1
  using F= bool(*)(const Sales_item &,const Sales_item &);
  std::multiset<Sales_item,F> 
    bookstore(F);*/
    //2
    typedef bool(*c)(const Sales_item &,const Sales_item &);
    std::multiset<Sales_item,c> bookstore(pcompareIsbn);
    /*
    *
    *不能使用后置返回类型，auto 主要是与decltype配合使用
    *
    */
}