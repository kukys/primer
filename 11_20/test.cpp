/*
��д11.1����ϰ����367ҳ���ĵ��ʼ�������ʹ��insert�����±����.
����Ϊ�Ǹ���������ױ�д���Ķ���WHY?
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
        //ret.first��ȡ������map<string,size_t>::iterator;
        //ret.first->�Ե����������ã���ȡmap�е�Ԫ��  
      }
  }
  for(auto &t:word_count)
    {
      cout<<t.first<<" �ַ����� "<<t.second<<"��";
    }
  return 0;
}
//ʹ���±������Ӽ򵥣�������⣬��ʹ��insert����Ҫ���++ret.first->second;