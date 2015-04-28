#include<algorithm>
#include<list>
#include<iostream>
using std::list;
using std::cout;
using std::endl;
  int main()
  {
    list<int> lis={1,2,0,4,0,6,0,7,0,89,0};
    auto zero = find(lis.crbegin(),lis.crend(),0);
    auto it=zero.base();
    auto s=std::prev(it);//使用方法与next相似，不同的是prev返回的是it的第n个前驱迭代指针
    cout<<*s;

  }
/*#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <list>
std::list<int>::iterator
find_last_0(std::list<int> &l);
  int main()
  {
    std::list<int>  l = {1,2,3,4,0,5,6};
    auto it = find_last_0(l);
    std::cout << *it << "\n";
  }
  inline std::list<int>::iterator
find_last_0(std::list<int> &l)
{
    //! assumimg : 1 2 3 4 0 5 6

    //! 1 2 3 4 0 5 6
    //!         ^
    //! to which r_it refer.
    auto r_it = std::find(l.rbegin(), l.rend(), 0);

    //! 1 2 3 4 0 5 6
    //!           ^
    //! to which it refer.
    auto it = r_it.base();

    //! 1 2 3 4 0 5 6
    //!         ^
    //! to which --it refer.
    return std::prev(it);

}*/