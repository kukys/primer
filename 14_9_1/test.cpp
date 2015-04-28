#include <iostream>
#include <stdexcept>
class SmallInt
{
public:
  SmallInt(int i=0):val(i)
  {
    if(i<0||i>255)
    {
      throw std::out_of_range("Bad smallInt value");
    }
  }
 operator int() const {return val;}
private:
  std::size_t val;
};
int main(int argc, char const *argv[])
{
  SmallInt si;
  si=3.14;
  auto p=si+3.14;
  std::cout<<p<<std::endl;
  return 0;
}

