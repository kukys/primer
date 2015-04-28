#include<list>
#include<iostream>
using std::list;
  using std::cin;
    using std::cout;
      using std::endl;
        int main()
        {
          list<int> v1 ={0,1,2,3,4,5,6,7,8};
          auto iter = v1.begin();
          while(iter!=v1.end())
          {
            if(*iter%2)
              {
                iter = v1.insert(iter,*iter);
              }
           ++iter;
          }
          for(auto c:v1)
            {
              cout<<c<<endl;
            }
            return 0;  
          }