/*
重写TextQuery 和QueryResult类,用StrBlob代替vector<string>保存输入文件
*/
#ifndef  MY_12_32_H
#define  MY_12_32_H
#include"E:\MinGW\project\12_19\My_12_19.h"
using std::shared_ptr;

#include <iostream>
#include <fstream>
#include <map>
#include <set>

class QueryResult;
class TextQuery {
public:
    TextQuery(std::ifstream &);
    QueryResult query(const string&) const;
private:
    shared_ptr<StrBlob> input;
    std::map<string, shared_ptr<std::set<StrBlob::size_type>>> result;
};

class QueryResult {
public:
    friend std::ostream& print(std::ostream &, const QueryResult&);
public:
    QueryResult(const string &s, shared_ptr<std::set<StrBlob::size_type>> set, shared_ptr<StrBlob> v) : word(s), nos(set), input(v) {}
private:
    string word;
    shared_ptr<std::set<StrBlob::size_type>> nos;
    shared_ptr<StrBlob> input;
};

std::ostream& print(std::ostream &, const QueryResult&);

#endif //MY_12_32_h
