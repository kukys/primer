#include<list>
#include<deque>
#include<iostream>
using std::list;
  using std::deque;
    using std::cout;
      using std::endl;
    int main()
    {
      list<int> v1={1,2,3,4,5,6,7,8,9,10};
      deque<int> jishu;
      deque<int> oushu;
      
      list<int>::iterator it=v1.begin();
        while(it!=v1.end())
        {
          if((*it)%2==0)
            {
              oushu.push_back(*it);
            }
            else
              {
                jishu.push_back(*it);
              }
              it++;
        }
        cout<<"奇数是"<<endl;
        for(auto c:jishu)
          {
            cout<<c<<" ";
          }
         cout<<endl;
         cout<<"偶数是"<<endl;
         for(auto l:oushu)
          {
            cout<<l<<" ";
          }
          return 0;
    }