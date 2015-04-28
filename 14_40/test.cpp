#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using std::vector;
using std::string;
using std::cout;
using std::endl;
class Check
{
public:
  void biggies(vector<string>&,vector<string>::size_type l);
  using size_type =vector<string>::size_type;
  Check( size_type l):st(l){}
  bool operator()(const string& a)const
  {return a.size()>=st;}
private:
  size_type st;
};

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
  void Check::biggies(vector<string> &words,vector<string>::size_type sz)
      {
          elimDups(words);
          stable_sort(words.begin(),words.end(),
          [](const string &a,const string &b)
          {return a.size()<b.size();});
          auto wc = find_if(words.begin(),words.end(),Check(sz));
         // auto wc =words.begin();
          auto count = words.end()-wc;

          cout<<count<<" "<<make_plural(count,"word","s")<<" of length "<<sz<<" or longer "<<endl;

          for_each(wc,words.end(),

          [] (const string &s){cout<<s<<" ";});
          cout<<endl;
      }
  int main()
      {
          vector<string>v1 = {"a","aa","maoliwoaini","aaaa","aaaaa","aaaaaa","yangzhong"};
          Check c(7);
          c.biggies(v1,7);
          return 0;
      }
