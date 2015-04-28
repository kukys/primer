#include <functional>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using std::string;
using std::greater;
using std::not_equal_to;
using std::multiplies;
using std::cout;
using std::cin;
using std::endl;
 int main(int argc, char const *argv[])
 {
    /*greater<int> g;
    std::vector<int> vec1={123,23,1,23,4,99,1232,123,1234,45,678};
    auto beg = vec1.begin(),neg =vec1.end();
    int number =0;
    while(beg!=neg)
    {
      if(g(*beg,2000))
      {
        ++number;
      }
      beg++;
    }
    cout<<number<<endl;*/

    /*std::vector<string> vec2={"pooh","oj","pooh","pooh","pooh","pooh"};
    not_equal_to<string> Notequal;
    auto beg1 = vec2.begin(),neg1 =vec2.end();
    while(beg1!=neg1)
    {
        if(Notequal(*beg1,"pooh"))
          {
            cout<<*beg1<<endl;
            break;
          }
          ++beg1;
    }
    if(beg1==neg1)
    {
      cout<<"not_equal_to pooh"<<endl;
    }*/
    multiplies<int> mul;
    std::vector<int> vec3={1,2,3,4,5,6};
    auto beg =vec3.begin(),neg=vec3.end();
    while(beg!=neg)
    {
      cout<<mul(*beg,2)<<" ";
      ++beg;
    }
    return 0;
 }
