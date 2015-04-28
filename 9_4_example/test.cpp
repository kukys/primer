#include<vector>
#include<iostream>
using std::vector;
  using std::cout;
    using std::endl;
      int main()
      {
        vector<int> ivec;
        cout<<"ivec:size: "<<ivec.size()
        <<"   capacity: "<<ivec.capacity()<<endl;//size与capacity的区别
        
        for(vector<int>::size_type ix = 0;ix!=24;++ix)
          {
            ivec.push_back(ix);
          }
          ivec.reserve(50);   //设置新的内存空间
          while(ivec.size()!=ivec.capacity())
          {
            ivec.push_back(0);
          }
          ivec.push_back(1);
          ivec.shrink_to_fit();//返回多余的内存
          cout<<"ivec:size: "<<ivec.size()
        <<"   capacity: "<<ivec.capacity()<<endl;
        return 0;
      }