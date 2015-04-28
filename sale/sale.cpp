#include<iostream>
#include<string>
#include"Sales_Data.h"
using namespace std;
int main()
{
	Sales_Data book1,book2;
	double price=0;
	cin>>book1.bookNum>>book1.sold_Num>>price;
  book1.Price=book1.sold_Num*price;
	cin>>book2.bookNum>>book2.sold_Num>>price;
	book2.Price=book2.sold_Num*price;
	if(book1.bookNum==book2.bookNum)
		{
			auto totalNum=book1.sold_Num+book2.sold_Num;
			auto totalPrice=book1.Price+book2.Price;
			cout<<book1.bookNum<<' '<<totalNum<<' '<<totalPrice<<' '<<endl;
			if(totalPrice!=0)
				{
					cout<<' '<<totalPrice/totalNum<<endl;
				}
			else
				{
					cout<<"(no sales)"<<endl;
				}
			return 0;
		}
	else
		{
			cerr<<"Data must refer to the same ISBN"<<endl;
			return -1;
		}
}
