#include<vector>
#include<iostream>
using std::vector;
  using std::cout;
    using std::endl;
      int main()
      {
        vector<int> ivec;
        cout<<"ivec:size: "<<ivec.size()
        <<"   capacity: "<<ivec.capacity()<<endl;//size��capacity������
        
        for(vector<int>::size_type ix = 0;ix!=24;++ix)
          {
            ivec.push_back(ix);
          }
          ivec.reserve(50);   //�����µ��ڴ�ռ�
          while(ivec.size()!=ivec.capacity())
          {
            ivec.push_back(0);
          }
          ivec.push_back(1);
          ivec.shrink_to_fit();//���ض�����ڴ�
          cout<<"ivec:size: "<<ivec.size()
        <<"   capacity: "<<ivec.capacity()<<endl;
        return 0;
      }