#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using std::vector;
  using std::string;
    using std::cin;
      using std::cout;
        using std::endl;
             bool isShorter(const string &s1,const string &s2)
            {
              return s1.size()<s2.size();
            }
             void printwords(vector<string> &cc)
            {
              for(const auto &c:cc)
                {
                  cout<<c<<" ";
                }
                cout<<endl;
            }
            void elimDups(vector<string> &words)
            {
              /*
              *如果是
              *sort(words.begin(),words.end(),isShorter)
               输出结果就一直是排序后的结果
               不会进行后面的unique操作和erase操作?为什么
              */
              sort(words.begin(),words.end());
              printwords(words);
              auto end_unique = unique(words.begin(),words.end());
              printwords(words);
              words.erase(end_unique,words.end());
              printwords(words);
            }
            int main()
            {
              vector<string> v1 = {"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
              elimDups(v1);
              stable_sort(v1.begin(),v1.end(),isShorter);
              printwords(v1);
            }
          