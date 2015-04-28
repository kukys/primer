//My_14_7.h
#ifndef MY_14_7_H
#define MY_14_7_H
#include <memory>
#include <iostream>
class String
{
	friend std::ostream &operator<<(std::ostream &os,const String &str);
	friend bool operator==(const String &lhs,const String &rhs);
	friend bool operator!=(const String &lhs,const String &rhs);
	friend bool operator<(const String &lhs,const String &rhs);
public:
	String() : String("") {}
	String(const char *);
	String(const String&);
	String& operator=(const String&);

	char &operator[](std::size_t n )
	{return elements[n];}
	
	const char &operator[](std::size_t n)const
	{return elements[n];}
	~String();

	//const char *c_str() const { return elements; }
	size_t size() const { return end - elements; }
	size_t length() const { return end - elements - 1; }

private:
	std::pair<char*, char*> alloc_n_copy(const char*, const char*);
	void range_initializer(const char*, const char*);
	void free();

private:
	char *elements;
	char *end;
	std::allocator<char> alloc;
};
	std::ostream &operator<<(std::ostream &os,const String &str);
	bool operator==(const String &lhs,const String &rhs);
	bool operator!=(const String &lhs,const String &rhs);
	bool operator<(const String &lhs,const String &rhs);
#endif