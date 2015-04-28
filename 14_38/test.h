#ifndef TEST_H
#define TEST_H
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;

class Length
{
public:
    Length(size_t n):sz(n) {}
    bool operator()(string &s){ return s.size()==sz;}
private:
    size_t sz;
};

#endif //TEST_H
