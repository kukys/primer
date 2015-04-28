#include<numeric>
#include<iostream>
#include<vector>
#include<string>
using std::vector;
  using std::cin;
    using std::cout;
      using std::endl;
        using std::string;
        int main()
        {
          string number;
          vector<string> vec;
          while(cin>>number)
          {
            vec.push_back(number);
          }
          cin.clear();
          string str = accumulate(vec.cbegin(),vec.cend(),string(""));
          
          cout<<str<<endl;
          return 0;
        }