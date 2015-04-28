#include<numeric>
#include<iostream>
#include<vector>
using std::vector;
  using std::cin;
    using std::cout;
      using std::endl;
        int main()
        {
          int number;
          vector<double> vec;
          while(cin>>number)
          {
            vec.push_back(number);
          }
          cin.clear();
          int sum = accumulate(vec.cbegin(),vec.cend(),0);
          
          cout<<sum<<endl;
          return 0;
        }