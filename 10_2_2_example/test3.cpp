#include<iostream>
#include<iterator>
using std::cout;
  using std::cin;
    using std::copy;
      using std::begin;
        using std::end;
          using std::endl;
    int main()
    {
      int a1[] = {0,1,2,3,4,5,6,7,8,9};
      int a2[sizeof(a1)/sizeof(*a1)];
      
      auto ret=copy(begin(a1),end(a1),a2);
      cout<<ret<<'\t'<<end(a2);
      cout<<endl<<endl;
      for(auto c:a2)
        {
          cout<<c<<endl;
        }
      return 0;
    }