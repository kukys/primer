#ifndef TEST_H
#define TEST_H
#include <string>
#include <iostream>
#include  <vector>
#include <memory>
#include <set>
class Quote
{
public:
  //只能用于任何类型的Quote(包括右值引用类型)
  virtual Quote* clone()const &
  {
    std::cout<<"use Quote& "<<std::endl;
    return new Quote(*this);
  }
  //可用于可改变的右值
  virtual Quote* clone()&&
  {
    std::cout<<"use Quote&& "<<std::endl;
    return new Quote(std::move(*this));
  }
  friend   double print_total(std::ostream&, const Quote&,size_t);
  Quote():bookNo("nihai"),price(100){}
  Quote(const std::string& book,double sale_pricre):
        bookNo(book),price(sale_pricre){}
  std::string isbn() const {return bookNo;}
  //返回给定数量的书籍的销售总额
  //派生类负责改写并使用不同的折扣计算算法
  virtual double net_price(std::size_t n)const
  {return n * price;}
  virtual~Quote()=default;//对析构函数动态绑定
  Quote&operator=(const Quote &rhs)
  {
    bookNo=rhs.bookNo;
    price=rhs.price;
    return *this;
  }
private:
  std::string bookNo;
protected:
  double price =0.0;      //代表普通状态下不打折的价格
};
class Bulk_quote:public Quote
{
public:
  Bulk_quote* clone()const &
  {
    std::cout<<"use Bulk_quote& "<<std::endl;
    return new Bulk_quote(*this);
  }
  Bulk_quote* clone()&&
  {
    std::cout<<"use Bulk_quote&& "<<std::endl;
    return new Bulk_quote(std::move(*this));
  }
  Bulk_quote()=default;
  Bulk_quote(const std::string& book,
             double p,std::size_t qty,
             double disc):Quote(book,p),quantity(qty),discount(disc){}
  //覆盖基类的函数版本以实现一种新的的折扣政策
  //using Disc_quote::Disc_quote;继承Disc_quote的构造函数
  double net_price(std::size_t n)const override;
  Bulk_quote& operator=(const Bulk_quote&rhs)
  {
    Quote::operator=(rhs);
    return *this;
  }
  ~Bulk_quote()=default;
protected:
  std::size_t quantity =0.0;
  double discount      =0.0;
};
class BasKet
{
public:
  //bask使用合成的默认构造函数和拷贝控制成员
  //void add_item(const std::shared_ptr<Quote> &sale){items.insert(sale);}
  void add_item(const Quote& sale)
  {
    std::cout<<"add_item(const Quote&)"<<std::endl;
    items.insert(std::shared_ptr<Quote>(sale.clone())); }

  void add_item(Quote&& sale)
  {
    std::cout<<"add_item(const Quote&&）"<<std::endl;
    items.insert
    (std::shared_ptr<Quote>(std::move(sale).clone()));
  }
  //打印每本书的总价和购物篮中所有书的总价
  double  total_receipt(std::ostream& os)const;
private:
  //该函数用于比较shared_ptr,multiset成员会用到它
  static bool compare(const std::shared_ptr<Quote>& lhs,
                      const std::shared_ptr<Quote>& rhs)
  {return lhs->isbn()<rhs->isbn();}
  //muliset保存多个报价,按照compare成员排序;
  std::multiset<std::shared_ptr<Quote>,decltype(compare)*>
          items{compare};//使用类内初始化c++11
};
#endif
//TEST_H
