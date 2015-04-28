/**
 * 14_35 36
 */
#include <string>
using std::istream;
using std::string;
using std::cout;
using std::cin;
class PrintString
{
public:
  PrintString(istream& i=cin):is(i){}
  string operator()(void)const
  {
    string s;
    getline(is,s);
    if(is)
      return s;
    else
      return "";
  }
private:
  istream& is;
};
