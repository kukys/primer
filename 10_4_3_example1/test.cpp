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
    //��first��last������֮��Ĳ��ָ����ַ���
    return 0;    
  }