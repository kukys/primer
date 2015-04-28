#include<vector>
#include<iostream>
#include <algorithm> 
using std::vector;
  using std::endl;
    using std::cout;
      int main()
      {
        int val=9;
        vector<int>v1{1,2,3,4,5,6,7,8,9,0};
        fill(v1.begin(),v1.end(),val);  //会修改它的值，不能用cbegin或cend;
        for(auto c:v1)
          {
            cout<<c<<endl;
          }
          return 0;
      }