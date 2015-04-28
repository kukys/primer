/*
*在15章中我们将会扩展系统，在QueryResult类中将会需要一些额外的成员
添加名为begin和end的成员,返回迭代器,指向一个给定查询返回的行号的set中的位置。
再添加一个shared_ptr的get_file成员,指向QueryResult对象中的文件.
*/
#ifndef  MY_12_33H
#define  MY_12_33_H
#include <string>
#include<iterator>
using std::string;

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;
#include <iostream>
#include <fstream>
#include <map>
#include <set>

class QueryResult;
class TextQuery {
public:
    using LineNo = vector<string>::size_type;
    TextQuery(std::ifstream &);
    QueryResult query(const string&) const;
private:
    shared_ptr<vector<string>> input;
    std::map<string, shared_ptr<std::set<LineNo>>> result;
};

class QueryResult {
public:
    using ResultIter = std::set<TextQuery::LineNo>::iterator;
    friend std::ostream& print(std::ostream &, const QueryResult&);
public:
    QueryResult(const string &s, shared_ptr<std::set<TextQuery::LineNo>> set, shared_ptr<vector<string>> v) : word(s), nos(set), input(v) {}
    ResultIter begin () const {return nos->begin();}
    ResultIter end ()const {return nos->end();}
    shared_ptr<vector<string>> get_file() const { return input; }
private:
    string word;
    shared_ptr<std::set<TextQuery::LineNo>> nos;
    shared_ptr<vector<string>> input;
};

std::ostream& print(std::ostream &, const QueryResult&);
#endif //MY_12_33_h
