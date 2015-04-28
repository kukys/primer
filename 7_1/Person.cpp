#include"Person.h"
int main()
{
	Person p;
	read(std::cin,p);
	print(std::cout,p);
	return 0;
}
	std::ostream &print(std::ostream &os, const Person &p)
{
    os<<p.getName()<<" "<<p.address;
    return os;
}


std::istream &read(std::istream &is, Person &p)
{
    is>>p.name>>p.address;
    return is;
}


