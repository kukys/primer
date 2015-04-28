#include "test.h"
using std::multiset;
using std::shared_ptr;
using std::make_shared;
using std::ostream;
//using std::std::vector<char> v;;
using std::endl;
using std::cout;
double Bulk_quote::net_price(std::size_t cnt)const
{
  if(cnt>=quantity)
    return cnt*(1-discount)*price;
  return cnt * price;
}
double print_total(std::ostream& os, const Quote& item,size_t n)
{
  double ret =item.net_price(n);
  os<<"ISBN: "<<item.isbn()
    <<" # sold: "<<n<<" total due: "<<ret<<endl;
    return ret;
}
double BasKet::total_receipt(std::ostream& os)const
 {
    double sum=0.0;
    for (auto iter = items.cbegin(); iter!=items.cend();iter=items.upper_bound(*iter))
    {
      sum+=print_total(os,**iter,items.count(*iter));
    }
    os<<"Total sale: "<<sum<<std::endl;
    return sum;
 }
int main(int argc, char const *argv[])
{
  auto i=Quote();
  auto j=i;
  Quote q("123",45);
  Bulk_quote q1("456",45,1,0.15);
  BasKet bask;
  bask.add_item(j);
  bask.total_receipt(cout);
  return 0;
}
//for kuky
//for life
//for google
//15_29
//15_30
