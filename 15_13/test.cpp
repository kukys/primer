/**
 * 15_13 15_14
 */
#include <string>
#include <iostream>
using std::endl;
using std::cout;
using std::ostream;
using std::string;
class base
{
public:
  //base(const string& s):basename(s){}
  string name(){return basename;}
  virtual void print(ostream& os)
  {
    os<<basename;
  }
private:
  string basename="Hello World";
};
class derived : public base
{
public:
  //derived(const string& s,int j):base(s),i(j){}
  void print(ostream& os) override
  {
    base::print(os);
    os<<" "<<i;
  }
private:
  string pname="yang";
  int i=1;
};
int main(int argc, char const *argv[])
{
  base bobj;
  base *bp1=&bobj;
  base &br1=bobj;

  derived dobj;
  base *bp2=&dobj;
  base &br2=dobj;
  bobj.print(cout);//base
  cout<<endl;
  dobj.print(cout);//derived
  cout<<endl;
  bp1->name();//base
  bp2->name();//dervied
  br1.print(cout);//bae
  cout<<endl;
  br2.print(cout);//derived
//把基类指针或引用绑定在派生类上
  return 0;
}
/**
 * for kuky
 * for life
 * for google
 */
