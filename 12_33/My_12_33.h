/*
*��15�������ǽ�����չϵͳ����QueryResult���н�����ҪһЩ����ĳ�Ա
�����Ϊbegin��end�ĳ�Ա,���ص�����,ָ��һ��������ѯ���ص��кŵ�set�е�λ�á�
�����һ��shared_ptr��get_file��Ա,ָ��QueryResult�����е��ļ�.
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
