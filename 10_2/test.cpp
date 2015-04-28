#include<algorithm>
#include<list>
#include<iostream>
#include<string>
using std::list;
  using std::cin;
  using std::cout;
    using std::endl;
      using std::string;
      int main()
      {
        list<string>v1;
        string val="A",number;
        while(cin>>number)
        {
          v1.push_back(number);
        }
        cin.clear();
        auto reslut = count(v1.cbegin(),v1.cend(),val);
        
        cout<<reslut<<endl;
        return 0;
      }