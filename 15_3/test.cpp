/*
15_3 15_11
 */
#ifndef TEST_H
#define TEST_H
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
        bookNo(book),price(sale_pricre){}
  std::string isbn() const {return bookNo;}
  //返回给定数量的书籍的销售总额
  //派生类负责改写并使用不同的折扣计算算法
  virtual double net_price(std::size_t n)const
  {return n * price;}

  virtual void debug()const
  {
    cout<<this->bookNo<<'\t'<<this->price<<endl;
  }
  virtual~Quote()=default;//对析构函数动态绑定
private:
  std::string bookNo;
protected:
  double price =0.0;      //代表普通状态下不打折的价格
};
class Bulk_quote:public Quote
{
public:
  Bulk_quote()=default;
  Bulk_quote(const std::string& book,
             double p,std::size_t qty,
             double disc):Quote(book,p),
             min_qty(qty),discount(disc){}
  //覆盖基类的函数版本以实现基于大量购买的折扣政策

  double net_price(std::size_t n)const override;
  void debug()const override
  {
    cout<<this->max_qty<<'\t'<<this->min_qty<<'\t'
    <<this->discount<<endl;
  }
private:
  std::size_t max_qty =10;
  std::size_t min_qty =0;//使用折扣的最小购买量
  double discount=0.0;   //以小数表示折扣
};
double Bulk_quote::net_price(std::size_t cnt)const
{
  if(cnt>=min_qty&&cnt<=max_qty)
    return cnt * (1-discount)*price;
  else if (cnt>max_qty)
  {
    double bas_price=(cnt-max_qty)*price;
    return (max_qty * (1-discount)*price)+bas_price;
  }
  return cnt * price;
}
#endif//TEST_H

  double print_total(std::ostream& os, const Quote& item,size_t n)
  {
    double ret =item.net_price(n);
    os<<"ISBN: "<<item.isbn()
      <<" # sold: "<<n<<" total due: "<<ret<<endl;
      return ret;
  }
int main(int argc, char const *argv[])
{
  std::string book1("c++ primer 5th");
  Quote basic(book1,2.8);
  print_total(cout,basic,2);
  basic.debug();
  std::string book2("Effect c++");
  Bulk_quote bulk(book2,1,3,0.1);
  print_total(cout,bulk,11);
  bulk.debug();
  //bulk.Quote::debug();调用Quote的版本
  return 0;
}
/*
15_12
有没有必要将一个成员函数同时声明称override和final吗？为什么
  answer:
  Sure. override means overriding(覆盖) the same name virtual function in base class.
  final means preventing any overriding this virtual function by any derived classes that are more lower at the hierachy .
 */
//for kuky
//for life
//for google
