#include<iostream>
#include<iterator>
#include<algorithm>

#include<vector>
using std::cout;
  using std::endl;
    using std::vector;
      
    int main()
    {
      vector<int> vec;
      fill_n(back_inserter(vec),10,0);
      
      for(auto c:vec)
      {
        cout<<c<<endl;
      }
      return 0;
    }