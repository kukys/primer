class Base
{
public:
  void pub_mem();
protected:
  int prot_mem;
private:
  char priv_mem;
};
class Pub_Derv : public Base
{};
struct Priv_Derv : private Base
{};
struct Prot_Derv : protected Base
{};
struct Derived_from_Public : public Pub_Derv
{};
struct Derived_from_Private: public Priv_Derv
{};
struct Derived_from_Protect : public Prot_Derv
{};
int main(int argc, char const *argv[])
{
  Base *p;
  //Pub_Derv d1;
  //p =&d1;//d1的类型是pub_Derv
  //实现派生类向基类的转变(公有继承)
  //Priv_Derv d2;
  //p=&d2;//d2的类型是Pri_Derv
  //私有继承不能实现派生类向基类的转变
  //Prot_Derv d3;
  //p=&d3;//d3的类型是Prot_Derv
  //保护继承也不能实现派生类向基类的转变
  //Derived_from_Public dd1;
  //p=&dd1;//dd1的类型是Derive_from_Public
  //基类Pub_Derv公有继承Base，所以派生类可以实现向基类的转变
  //Derived_from_Private dd2;
  //p=&dd2;//dd2的类型是Derive_from_Private
  //不能
  //Derived_from_Protect dd3;
  p=&dd3;//dd3的类型是Derive_from_Protected
  //不能
  return 0;
}

//15_18
