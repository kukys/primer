#include<set>
#include<iostream>
using namespace std;
int main()
{
  set<int > iset={0,1,2,3,4,5,6,7,8,9};
  set<int>::iterator set_it=iset.begin();
    if(set_it!=iset.end())
      {
        //*set_it=42;错误的，set里的关键字类型是只读的。
        cout<< *set_it<<endl;
      }
      return 0;
}