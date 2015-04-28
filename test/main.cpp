#include<iostream>
/*
*这是一个简单的程序
*/
using namespace std;
#include"Sales_item.h"
int main()
{
	Sales_item book;
    if(cin>>book)
	{
		Sales_item book1;
		while(cin>>book1)
		{
			if(book.isbn()==book1.isbn())
			{
			book+=book1;
			}
			else
			{
				cout<<book<<endl;
				book=book1;
			}
		}
		cout<<book;
	}else
	{
		cerr<<"no book"<<endl;
		return -1;
	}
	return 0;
}
