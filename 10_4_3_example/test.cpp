#include<iostream>
#include<vector>
int main()
{
  std::vector<int> vec={0,1,2,3,4,5,6,7,8,9,10};
  for(auto r_iter=vec.crbegin();r_iter!=vec.crend();++r_iter)
  {
    std::cout<<*r_iter<<std::endl;
  }
}