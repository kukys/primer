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
              *�����
              *sort(words.begin(),words.end(),isShorter)
               ��������һֱ�������Ľ��
               ������к����unique������erase����?Ϊʲô
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
          