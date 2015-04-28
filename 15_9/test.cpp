class A
{
public:
  virtual void item();
};
class B:public A
{
  void item()override;
};

void print (A&a)
{
  cout<<a.item;//静态类型为A&
  //动态类型看我们传入的对象类型
}
void print (A*a)
{
  coout<<a->item;//同上
}
//for kuky
//for life
//for google
