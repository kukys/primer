#include<algorithm>
#include<vector>
#include<list>
#include<iterator>
#include<iostream>
using std::vector;
  using std::list;
    using std::cout;
      int main()
      {
        vector<int>vec={1,1,2,2,3,3,4,4,5,5,0,0};
        list<int>lst;
        sort(vec.begin(),vec.end());
        
        unique_copy(vec.begin(),vec.end(), back_inserter(lst));
        
        for(auto c: lst)
          {
            cout<<c<<" ";
          }
          return 0;
      }