#include<vector>
#include<iostream>
#include<string>
using std::vector;
  using std::cout;
    using std::endl;
      using std::string;
      int main()
      {
      vector<string> c={"y"};
      if(!c.empty())
        {
          auto val1 = *c.begin();
          auto val2 = c.front();
          //auto val3 = *(--last);
          auto val4 = c.back();
                cout<<val1<<endl;
        cout<<val2<<endl;
        //cout<<val3<<endl;
        cout<<val4<<endl;
        }
      return 0;
      }
      