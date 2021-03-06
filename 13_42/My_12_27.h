#ifndef  MY_12_27_H
#define  MY_12_27_H
#include <string>
#include"My_13_39.h"
using std::string;
#include <memory>
using std::shared_ptr;


#include <fstream>
#include <map>
#include <set>

class StrBlob;
class QueryResult;
class TextQuery {
public:
    using LineNo = string::size_type;
    TextQuery(std::ifstream &);
    QueryResult query(const string&) const;
private:
    shared_ptr<StrVec> input;
    std::map<string, shared_ptr<std::set<LineNo>>> result;
};

class QueryResult {
public:
    friend std::ostream& print(std::ostream &, const QueryResult&);
public:
    QueryResult(const string &s, shared_ptr<std::set<TextQuery::LineNo>> set, shared_ptr<StrVec> v) : word(s), nos(set), input(v) {}
private:
    string word;
    shared_ptr<std::set<TextQuery::LineNo>> nos;
    shared_ptr<StrVec> input;
};

std::ostream& print(std::ostream &, const QueryResult&);

#endif //MY_12_27_h