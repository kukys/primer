class Base
{
public:
  void memfcn(Base& b){b=*this;}
};
struct Pub_Derv : public Base
{
  void memfcn(Base& b){b=*this;}
  //legal
};
struct Priv_Derv : private Base
{
  void memfcn(Base& b){b=*this;}
  //legal
};
struct Prot_Derv : protected Base
{

  void memfcn(Base& b){b=*this;}
  //legal
};
struct Derived_from_Public : public Pub_Derv
{
  void memfcn(Base& b){b=*this;}
  //legal
};
struct Derived_from_Private: public Priv_Derv
{
  //void memfcn(Base& b){b=*this;}
  //illegal
};
struct Derived_from_Protect : public Prot_Derv
{
  void memfcn(Base& b){b=*this;}
  //legal
};
int main(int argc, char const *argv[])
{
  Base b;
  Derived_from_Protect p;
  p.memfcn(b);
  return 0;
}
