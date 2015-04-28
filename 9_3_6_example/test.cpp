#include<vector>
#include<iostream>
using std::vector;
  using std::cin;
    using std::cout;
      using std::endl;
        int main()
        {
          vector<int> v1 ={0,1,2,3,4,5,6,7,8};
          auto iter = v1.begin();
          while(iter!=v1.end())
          {
            if(*iter%2)
              {
                iter = v1.insert(iter,*iter++);//£¨*iter£©
                ++iter;                        //iter+=2;
              }
              else
              {
                  iter = v1.erase(iter);
              }
          }
          for(auto c:v1)
            {
              cout<<c<<endl;
            }
            return 0;  
          }