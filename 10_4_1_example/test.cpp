#include<list>
#include<iostream>
#include<algorithm>
#include<iterator>
using std::list;
  using std::cout;
    using std::cin;
      using std::endl;
        int main()
        {
          list<int>lst={1,2,3,4};
          list<int>lst1={5};
          list<int>lst2={5};
          list<int>lst3={5};
          
          copy(lst.begin(),lst.end(),back_inserter(lst1));
          
          copy(lst.begin(),lst.end(),front_inserter(lst2));
          
          copy(lst.begin(),lst.end(),inserter(lst3,lst3.begin()));
          
          for(auto c1:lst1)
            {
              cout<<c1<<" ";
            }
            cout<<endl;
            for(auto c2:lst2)
            {
              cout<<c2<<" ";
            }
            cout<<endl;
            for(auto c3:lst3)
            {
              cout<<c3<<" ";
            }
            cout<<endl;
            return 0;
        }