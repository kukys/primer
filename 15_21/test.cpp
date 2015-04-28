#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
class People
{
public:
  People()=default;
  People(unsigned int i,const string& n,bool m):age(i),name(n),is_male(m){}
  virtual void human()const
  {
    cout<<"age "<<this->age<<" is_male ? = "
        <<this->is_male<<" name "<<this->name<<endl;
  }
private:
  unsigned int age =0.0;
  bool is_male     = true;
protected:
  string name      =" ";
};

class People_Work :public People
{
public:
  People_Work()=default;
  People_Work(unsigned int i,const string& n,bool m,const string& w)
              :People(i,n,m),work(w){}
  void human()const =0;
protected:
  string work=" ";
};

class Teacher :public People_Work
{
public:
  Teacher(unsigned int i,const string& n,bool m,const string& w):People_Work(i,n,m,w){}
  void human()const override
  {
    cout<<" name: "<<this->name
        <<" work "<<this->work<<endl;
  }
};
int main(int argc, char const *argv[])
{
  Teacher T(23,"杨忠",true,"Teacher");
  People p(23,"杨忠",true);
  p.human();
  T.human();
  return 0;
}
