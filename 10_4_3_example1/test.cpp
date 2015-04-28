#include<string>
#include<iostream>
#include<algorithm>
using std::string;
using std::cout;
using std::endl;
int main()
  {
    string line="i love you, dear!";
    auto comma = find(line.crbegin(),line.crend(),',');
    cout<<string(comma.base(),line.cend())<<endl;//string &assign(const_iterator first,const_itertor last);
    //把first和last迭代器之间的部分赋给字符串
    return 0;    
  }