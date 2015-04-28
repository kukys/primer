//main.cpp
//incude 14_26 18 16
#include "My_14_7.h"
#include <algorithm>
#include <vector>
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
       //std::cout<<"use :String(const String&s)"<<std::endl;
      }
      String&String::operator =(const String &rhs)
      {
        auto data = alloc_n_copy(rhs.elements,rhs.end);
        free();
        elements = data.first;
        end = data.second;
        //std:: cout<<"use String::operator =(const String &rhs)"<<std::endl;
        return *this;
    }
    std::ostream &operator<<(std::ostream &os,const String &str)
    {
    	os<<str.elements<<str.end;
    	return os;
    }
    bool operator==(const String&lhs,const String &rhs)
    {
    	return lhs.elements==rhs.elements&&lhs.end==rhs.end;
    }
    bool operator!=(const String &lhs,const String &rhs)
	{
		return !(lhs==rhs);
	}
	bool operator<(const String &lhs,const String &rhs)
	{
		if (lhs!=rhs)
		{
			return lhs.size()<rhs.size();
		}
		else
			return false;
	}
int main()
{
  vector<String> vec;
  String s = "hate" ;
  s[1]='o';
  String v ="yag";
  std::cout<<s<<"  s<v?"<<std::endl;
  if(s<v)
  	{
  		std::cout<<"yes";
  	}
  	else
  		std::cout<<"no";
  vec.push_back(s);
  return 0;
}