#include<list>
#include<iostream>
#include<string>
using std::string;
  using std::cout;
    using std::list;
      using std::cin;
      int main()
      {
        list<string>v1;
        string word;
        while(cin>>word)
        {
          v1.push_back(word);
        }
         for(auto c:v1)
          {
            cout<<c<<" ";
          }
          return 0;
      }
      