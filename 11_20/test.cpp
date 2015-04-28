/*
重写11.1节练习（第367页）的单词计数程序，使用insert代替下标操作.
你认为那个程序更容易编写和阅读？WHY?
*/
#include<map>
#include<iostream>
using namespace std;
int main()
{
  map<string,size_t>word_count;
  string word;
  while(cin>>word)
  {
    auto ret =word_count.insert({word,1});
    if(!ret.second)
      {
        ++ret.first->second;
        //ret.first获取迭代器map<string,size_t>::iterator;
        //ret.first->对迭代器解引用，提取map中的元素  
      }
  }
  for(auto &t:word_count)
    {
      cout<<t.first<<" 字符出现 "<<t.second<<"次";
    }
  return 0;
}
//使用下标程序更加简单，容易理解，而使用insert则需要理解++ret.first->second;