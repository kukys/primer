#include<forward_list>
#include<iostream>
#include<string>
using std::forward_list;
  using std::cin;
    using std::cout;
      using std::endl;
        using std::string;
        void insert(forward_list<string> &v1 , const string &s1, const string &s2)
        {
          auto prev = v1.before_begin();
          auto curr = v1.begin();
          while(curr!=v1.end())
          {
            if(*curr==s1)
              {
                v1.insert_after(curr,s2);
                return;                          //找到元素,直接返回
              }
              prev=curr;
              ++curr;  
          }
           v1.insert_after(prev,s2);
           return;                              //必须加return.
        }
        int main()
        {
          string str1="hello";
          string str2="world";
          forward_list<string> flst={"yzz","hello","BYE"};
          insert(flst,str1,str2);
          for(auto c:flst)
            {
              cout<<c<<endl;
            }
        }