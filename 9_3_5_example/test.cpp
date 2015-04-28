#include<list>
#include<iostream>
using std::list;
  using std::cin;
    using std::cout;
      using std::endl;
        int main()
        {
          list<int> l1(2,42);
          l1.resize(3,-1);
          l1.resize(1,0);
          for(auto c:l1)
            {
              cout<<c<<endl;
            }
            cout<<l1.size();
          }