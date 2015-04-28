#include<iostream>
#include<vector>
#include<list>
using std::vector;
  using std::cout;
    using std::endl;
      using std::list;
      int main()
      {
        bool a=true;
        list<int>v1={1,2,3,4,5,6,7};
        vector<int>v2={1,2,3,4,5,6,7};
        if(v1.size()!=v2.size())
          {
            a=false;
          }
          else
            {
              list<int>::iterator li=v1.begin();
                vector<int>::iterator vec=v2.begin();
              while(li!=v1.end())
              {
                  if(*li++!=*vec++)
                    {
                      a=false;
                      break;
                    }
              }    
            
            if(a)
              {
                cout<<"两个容器相等";
              }
              else
                cout<<"两个容器不相等";
              }
                return 0;
      }