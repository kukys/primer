/*
13_44  13_47  13_48
*/
#include "My_13_44.h"
#include <algorithm>
#include <iostream>
#include<vector>
using std::vector;

std::pair<char*, char*>
  String:: alloc_n_copy(const char*b, const char*e)
    {
      
      auto data = alloc.allocate(e- b );
     return {data,std::uninitialized_copy(b,e,data)};
    }
    
String::String(const char *s)
  {
    char *sl = const_cast<char *>(s);
   while(*sl)//确保s存在
    {
       ++sl;
    }
     range_initializer(s, ++sl);
  }
  String ::~String()
  {
    free();
  }
void String:: range_initializer(const char*lhs, const char*rhs)
  {
    auto str =alloc_n_copy(lhs,rhs);
    elements = str.first;
    end = str . second;
  }
  void String::free()
   {
      if (elements) {
		std::for_each(elements, end, [this](char &c){ alloc.destroy(&c); });
		alloc.deallocate(elements, end - elements);
	}	
  }
    String ::String(const String&rhs)
      {
         range_initializer(rhs.elements,rhs.end);
       std::cout<<"use :String(const String&s)"<<std::endl;
      }
      String&String::operator =(const String &rhs)
        {
          auto data = alloc_n_copy(rhs.elements,rhs.end);
          free();
          elements = data.first;
          end = data.second;
        std:: cout<<"use String::operator =(const String &rhs)"<<std::endl;
        return *this;
        }

int main()
{
  vector<String> vec;
  String s = "hate" ;
  String d = "hate" ;
  vec.push_back(s);
  vec.push_back(d);
  vec.push_back(d);
  vec.push_back(s);
//拷贝构造函数被调用的两次，这是因为，在第一次push_back时，vector的capacity是1,是正常调用一次拷贝构造；
//而第二次push_back时，会发现容量不够了，stl会重新分配一个old_size的两倍的空间，
//除了新push进来的数据会放在这个新空间，调用一次拷贝构造，原来已经有的数据也要搬过来的，
    return 0;
}