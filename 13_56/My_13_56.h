#ifndef MY_13_56_H
#define MY_13_56_H
#include<vector>
#include<algorithm>
#include<iostream>
using std::vector;
using std::cout;
using std::cin;
using std::endl;
class Foo
{
  public:
    Foo sorted()&&;
    Foo sorted()const &;
    void ints ();
    private:
      vector<int> data;
};
Foo Foo::sorted()&&
  {
  sort(data.begin(),data.end());
  cout<<"sorted()&&"<<endl;
  return *this;
  }
 /*Foo Foo::sorted() const &
    {
      Foo ret(*this);
      sort(ret.data.begin(),ret.data.end());
      cout<<"sorted() const &"<<endl;
      return ret;
    }
    */
   /* Foo Foo::sorted() const &
    {
      Foo ret(*this);

      cout<<"sorted() const &"<<endl;
      return ret.sorted() ;
    }会一直循环调用函数sorted() const &
    */

Foo Foo::sorted() const &
  {
  cout<<"sorted() const &"<<endl;
  return { Foo(*this).sorted()};
  }
#endif//MY_13_56_H
