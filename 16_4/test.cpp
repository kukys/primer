#include <iostream>
#include <vector>
#include <string>
#include <list>
using std::list;
using std::string;
using std::cout;
using std::endl;
template <typename iteratorT,typename valueT>
iteratorT find(const iteratorT& first,const iteratorT& last,const valueT& value)
{
  auto iter=first;
  while(iter!=last)
  {
    if(*iter==value)
    {
      return iter;
    }
    ++iter;
  }
  return iter;
}
int main(int argc, char const *argv[])
{
  std::vector<int> v={1,2,3,4,5};
  cout<<*find(v.begin(),v.end(),5)<<endl;
  list<string> l = {"aa","bb","cc","dd","ee","ff","gg"};
  cout << *find(l.cbegin(), l.cend(), "aa") <<endl;
  return 0;
}
