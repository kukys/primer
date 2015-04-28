 #include<iostream>
#include<vector>
#include<algorithm>
using std::cout;
  using std::vector;
    using std::endl;

int main()
{
   int search_value = 42;
   int ival;
   vector<int> vec ={21,23};

   auto result = find(vec.begin() , vec.end() , search_value);

  cout<<"The value "<<search_value
      <<(result == vec.end() ? " is not present" : "is present")
      <<endl;

  return 0;
}