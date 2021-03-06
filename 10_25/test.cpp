#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using std::vector;
  using std::string;
    using std::cout;
      using std::endl;
                using namespace std::placeholders;
                  bool check_size(const string &s , string::size_type sz)
            {
              return s.size()<sz;
            } 
        void elimDups(vector<string> &words)
            {
              sort(words.begin(),words.end());
              auto end_unique = unique(words.begin(),words.end());
              words.erase(end_unique,words.end());
            }
            string make_plural(size_t ctr,const string &word,const string &ending)
            {
              return (ctr>1) ? word + ending :word;
            }
        void biggies(vector<string> &words,vector<string>::size_type sz)
            {
                elimDups(words);
                stable_sort(words.begin(),words.end(),
                [](const string &a,const string &b)
                {return a.size()<b.size();});
                auto wc = stable_partition(words.begin(),words.end(), bind(check_size, _1, sz));
                auto count = words.end()-wc;
                
                cout<<count<<" "<<make_plural(count,"word","s")<<" of length "<<sz<<" or longer "<<endl;
                
                for_each(wc,words.end(),

                [] (const string &s){cout<<s<<" ";});
                cout<<endl;
            }
        int main()
            {
                vector<string>v1 = {"a","aa","maoliwoaini","aaaa","aaaaa","aaaaaa","yangzhong"};
                vector<string>::size_type st=7;
                biggies(v1,st);
                return 0;
            }