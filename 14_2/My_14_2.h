/*
include<14_2 14_6 14_9 14_3_1 14_20 14_21>
*/
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>


class Sales_data
{
    //! friends for the newly added overloaded operators
    friend Sales_data 
    operator+(const Sales_data& lhs, const Sales_data& rhs);

    friend std::ostream&
    operator << (std::ostream& os, const Sales_data& s);

    friend std::istream&
    operator >> (std::istream& is,  Sales_data& s);

    friend bool 
    operator ==(const Sales_data &lhs ,const Sales_data &rhs);

    friend bool
    operator !=(const Sales_data &lhs ,const Sales_data &rhs);

    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);

public:
	// constructors
	Sales_data() = default;
	Sales_data(const std::string &s): bookNo(s) { }
	Sales_data(const std::string &s, unsigned n, double p):
	           bookNo(s), units_sold(n), revenue(p*n) { }
	Sales_data(std::istream &);

	Sales_data &operator+=(const Sales_data& );
	Sales_data &operator=(const Sales_data&);
	Sales_data &operator=(const std::string&);
    //! overloaded operators added 10.Jan.2014 for ex14.2


	// operations on Sales_data objects
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
//! overloaded operators added 10.Jan.2014 for ex14.2
Sales_data
operator+(const Sales_data& lhs, const Sales_data& rhs);

std::ostream&
operator << (std::ostream& os, const Sales_data& s);

std::istream&
operator >> (std::istream& is,  Sales_data& s);

bool operator==(const Sales_data &lhs,const Sales_data &rhs);

bool operator!=(const Sales_data &lhs,const Sales_data &rhs);
// nonmember Sales_data interface functions
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

// used in future chapters
inline 
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}
#endif