#include "My_14_2.h"
#include <iostream>
using std::istream; 
using std::ostream;

Sales_data::Sales_data(std::istream &is) 
{
	// read will read a transaction from is into this object
	read(is, *this);
}

double 
Sales_data::avg_price() const {
	if (units_sold)
		return revenue/units_sold;
	else
		return 0;
}

// add the value of the given Sales_data into this object
Sales_data& 
Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold; // add the members of rhs into 
	revenue += rhs.revenue;       // the members of ``this'' object
	return *this; // return the object on which the function was called
}

Sales_data 
add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;  // copy data members from lhs into sum
	sum.combine(rhs);      // add data members from rhs into sum
	return sum;
}

// transactions contain ISBN, number of copies sold, and sales price
istream&
read(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream&
print(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " 
	   << item.revenue << " " << item.avg_price();
	return os;
}
std::ostream&operator<<(std::ostream &os,const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " 
	   << item.revenue << " " << item.avg_price();
	return os;
}
std::istream&operator>>(std::istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	if (is)
	{
		item.revenue = price * item.units_sold;	
	}
	else
		item = Sales_data();
	return is;
}
Sales_data&Sales_data::operator=(const Sales_data&rhs)
{
	if(*this!=rhs)
	{
		units_sold =rhs.units_sold;
		revenue =rhs.revenue;
	}
	return *this;
}
Sales_data&Sales_data::operator=(const std::string&rhs)
{
	isbn()=rhs;
	return *this;
}
Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
	units_sold +=rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
} 
Sales_data operator+(const Sales_data &lhs,const Sales_data &rhs)
{
	Sales_data sum =lhs;
	sum += lhs;
	return sum;
}
bool operator==(const Sales_data &lhs,const Sales_data &rhs)
{
	return lhs.isbn()==rhs.isbn()&&
		   lhs.units_sold==rhs.units_sold;
		   lhs.revenue==rhs.revenue;
}
bool operator!=(const Sales_data &lhs,const Sales_data &rhs)
{
	return !(lhs==rhs);
}
int  main(int argc, char const *argv[])
{
	Sales_data book;
	std::cin>>book;

	std::cout<<book;
	return 0;
}
