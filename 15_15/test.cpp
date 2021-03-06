/*
15_3 15_11
 */
#include <string>
#include <iostream>
using std::endl;
using std::cout;
class Quote
{
public:
  friend   double print_total(std::ostream&, const Quote&,size_t);
  Quote()=default;
  Quote(const std::string& book,double sale_pricre):
        bookNo(book),price(sale_pricre){cout<<" Quote() "<<endl;}
  std::string isbn() const {return bookNo;}
  //返回给定数量的书籍的销售总额
  //派生类负责改写并使用不同的折扣计算算法
  virtual double net_price(std::size_t n)const
  {return n * price;}
  virtual~Quote(){cout<<" virtual~Quote"<<endl;}//对析构函数动态绑定
  Quote&operator=(const Quote &rhs)
  {
    bookNo=rhs.bookNo;
    price=rhs.price;
    cout<<" Quote&operator= "<<endl;
    return *this;
  }
private:
  std::string bookNo;
protected:
  double price =0.0;      //代表普通状态下不打折的价格
};
class Disc_quote:public Quote
{
public:
  Disc_quote()=default;
  Disc_quote(const std::string& book,double price,
             std::size_t qty,double disc):
             Quote(book,price),quantity(qty),discount(disc){cout<<"Disc_quote()"<<endl;}
  double net_price(std::size_t) const=0;//纯虚函数
  ~Disc_quote(){cout<<"~Disc_quote()"<<endl;}
protected:
  std::size_t quantity =0;//折扣使用的购买量
  double discount =0.0;//表示折扣的小数值
};
class Bulk_quote:public Disc_quote
{
public:
  Bulk_quote()=default;
  Bulk_quote(const std::string& book,
             double p,std::size_t qty,
             double disc):Disc_quote(book,p,qty,disc){cout<<"Bulk_quote()"<<endl;}
  //覆盖基类的函数版本以实现一种新的的折扣政策
  //using Disc_quote::Disc_quote;继承Disc_quote的构造函数
  double net_price(std::size_t n)const override;
  Bulk_quote& operator=(const Bulk_quote&rhs)
  {
    Disc_quote::operator=(rhs);
    cout<<"Bulk_quote& operator="<<endl;
    return *this;
  }
  ~Bulk_quote(){cout<<"~Bulk_quote"<<endl;}
};
double Bulk_quote::net_price(std::size_t cnt)const
{
  cout<<"Bulk_quote::net_price"<<endl;
  if(cnt>=quantity)
    return cnt * (1-discount)*price;
  return cnt * price;
}

class Limit_quote:public Disc_quote
{
public:
  Limit_quote()=default;
  Limit_quote(const std::string& book,
             double p,std::size_t qty,
             double disc):Disc_quote(book,p,qty,disc){cout<<"Limit_quote()"<<endl;}
  double net_price(std::size_t n)const override;
  ~Limit_quote(){cout<<"~Limit_quote"<<endl;}
private:
  double max_qty=10;
};
double Limit_quote::net_price(std::size_t cnt)const
{
  cout<<"Limit_quote::net_price"<<endl;
  if(cnt>max_qty)
  {
    return (cnt-max_qty)*price+max_qty*(1-discount)*price;
  }
  return cnt*(1-discount)*price;
}
double print_total(std::ostream& os, const Quote& item,size_t n)
{
  double ret =item.net_price(n);
  os<<"ISBN: "<<item.isbn()
    <<" # sold: "<<n<<" total due: "<<ret<<endl;
    return ret;
}
int main(int argc, char const *argv[])
{
  Bulk_quote b();
  Bulk_quote bulk("Effect c++",1,3,0.1);
  print_total(cout,bulk,12);
  cout<<"*********"<<endl;
  Limit_quote limit("more Effect c++",1,3,0.1);
  print_total(cout,limit,11);

  //Disc_quote n;
  return 0;
}
//for kuky
//for life
//for google
//15_17
//error: cannot declare variable 'n' to be of abstract type 'Disc_quote'
//15_26
