#include<vector>
#include<list>
#include<iostream>
#include<iterator>
using std::vector;
  using std::list;
    using std::cin;
      using std::cout;
        using std::endl;
      int main()
      {
        vector<int> vec;
        /*list<int>lst;
        int i;
        while(cin>>i)
        {
          lst.push_back(i);
        }
        vec.resize(lst.size());
      copy(lst.cbegin(),lst.cend(),vec.begin());
      for(auto c:vec)
        {
          cout<<c<<endl;
        }*/
        vec.reserve(10);
        fill_n(vec.begin(),10,0);
      }