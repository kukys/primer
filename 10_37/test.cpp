#include<vector>
#include<list>
#include<iostream>
#include<algorithm>
using std::vector;
using std::list;
using std::cout;
using std::endl;
int main()
{
  list<int> inverted_lis;//����
  list<int>lis;//����
  vector<int> vec={0,1,2,3,4,5,6,7,8,9};
    //��һ��������Ҫ����Ԫ�ص��׵�ַ��
    //�ڶ���������Ԫ�����һ��Ԫ�ص���һ��λ�ã�
    //�����������ǿ�����Ŀ�ĵ�ַ���׵�ַ��
  copy(vec.crbegin()+3,vec.crbegin()+8,std::back_inserter(inverted_lis));
  for(auto s:inverted_lis)
    {
      cout<<s<<"-";
    }
    cout<<endl;
  copy(vec.cbegin()+2,vec.cbegin()+7,std::back_inserter(lis));
   for(auto s:lis)
    {
      cout<<s<<"-";
    }
    cout<<endl;
}