#ifndef SALE_DATA_H
#define SALE_DATA_H
#include<string>
/*
头文件不应该包含using声明
*/
struct Sales_Data
{

	std::string bookNum;
	unsigned sold_Num=0;
	double Price=0.0;
	
};
#endif