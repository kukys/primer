#ifndef SALES_DATA_H
#define SALES_DATA_H
#include<string>
#include<iostream>
using std::istream;
using std::ostream;
using std::string;
class Sales_Data
{
	friend istream &read(istream &is,Sales_Data &p);
	friend ostream &print(ostream &os,const Sales_Data &p);
	friend Sales_Data add(const Sales_Data &fhs,const Sales_Data &hhs);
	public:
	//构造函数在const对象的构造过程中可以对其写值
	Sales_Data()=default;
	Sales_Data(const string &s):bookNo(s){}
	Sales_Data(const string &s,unsigned n,double p):bookNo(s),units_sold(n),revenue(p*n){}
	Sales_Data(istream&is)
 {
	double price=0;
	
	is>>this->bookNo>>this->units_sold>>price;
	
	this->revenue=this->units_sold*price;
 }
	
	string isbn() const{return bookNo;}
	Sales_Data & combine(const  Sales_Data&s) ;
	private:
	double avg_price() const;
	
	string bookNo;
	unsigned units_sold=0;
	double revenue=0;
};
istream &read(istream &is,Sales_Data &p);
ostream &print(ostream &os,const Sales_Data &p);
Sales_Data add(const Sales_Data &fhs,const Sales_Data &hhs);

#endif//SALES_DATA_H