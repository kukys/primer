#include<forward_list>
#include<iostream>
using std::forward_list;
  using std::cout;
    using std::cin;
      using std::endl;
        int main()
        {
          forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9,10};
          auto prev = flst.before_begin();  //��ʾflst��"��ǰԪ��"
          auto curr = flst.begin();        //��ʾflst�ĵ�һ��Ԫ��
          while(curr!=flst.end())
          {
            if(*curr%2)                    //ɾ������ 
              {
                curr = flst.erase_after(prev);
              }
              else
                {
                  prev = curr;
                  curr++;
                }
          }
          for(auto c:flst)
            {
              cout<<c<<endl;
            }
        }
          