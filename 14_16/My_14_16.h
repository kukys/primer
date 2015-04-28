/*
include 14_16 18 26
*/
#ifndef MY_14_16_H
#define MY_14_16_H



#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>
#include <iostream>
using std::vector; using std::string;

class StrBlobPtr;

class StrBlob {
public:
    using size_type = vector<string>::size_type;
    friend class StrBlobPtr;
    //赋值运算符
    friend bool operator==
    (const StrBlob &lhs,const StrBlob &rhs);
    friend bool operator!=
    (const StrBlob &lhs,const StrBlob &rhs);
    friend bool operator<(const StrBlob &lhs,const StrBlob &rhs);
    //下标
    std::string &operator[](std::size_t n)
    {
        return (*data)[n];
    }
    const std::string &operator[](std::size_t n)const
    {
        return (*data)[n];
    }

    StrBlobPtr begin();
    StrBlobPtr end();

    StrBlob():data(std::make_shared<vector<string>>()) { }
    StrBlob(std::initializer_list<string> il):data(std::make_shared<vector<string>>(il)) { }



    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const string &t) { data->push_back(t); }
    void pop_back() {
        check(0, "pop_back on empty StrBlob");
        data->pop_back();
    }

    std::string& front() {
        check(0, "front on empty StrBlob");
        return data->front();
    }

    std::string& back() {
        check(0, "back on empty StrBlob");
        return data->back();
    }

    const std::string& front() const {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    const std::string& back() const {
        check(0, "back on empty StrBlob");
        return data->back();
    }

private:
    void check(size_type i, const string &msg) const {
        if (i >= data->size()) throw std::out_of_range(msg);
    }

private:
    std::shared_ptr<vector<string>> data;
};
bool operator==(const StrBlob &lhs,const StrBlob &rhs)
    {return *lhs.data ==*rhs.data;}
bool operator!=(const StrBlob &lhs,const StrBlob &rhs)
    {return !(lhs==rhs);}
bool operator<(const StrBlob &lhs,const StrBlob &rhs)
    {
        if (!(lhs==rhs))
        {
            return lhs.size()<rhs.size();
        }
        else
            return false;
    }


//---------------------StrBlobPtr-----------------------------------------------
class StrBlobPtr {
    friend bool operator==
    (const StrBlobPtr &lhs,const StrBlobPtr &rhs);
    friend bool operator!=
    (const StrBlobPtr &lhs,const StrBlobPtr &rhs);
public:
    StrBlobPtr():curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0):wptr(a.data), curr(sz) { }
    bool operator!=(const StrBlobPtr& p) {return p.curr != curr; }
    string& deref() const {
        auto p = check(curr, "dereference past end");//到达尾部，不能增加
        return (*p)[curr];
    }
    StrBlobPtr& incr() {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }
    std::string &operator[](std::size_t n)
    {
        check(curr,"increment past end of StrBlobPtr");
        auto ret = wptr.lock();
        return (*ret)[n];
    }
    const std::string &operator[](std::size_t n) const
    {
        check(curr,"increment past end of StrBlobPtr");
        auto ret = wptr.lock();
        return (*ret)[n];
    }
    //重载递增递减运算符
    //前置++i
    StrBlobPtr& operator++();
    StrBlobPtr& operator--();
    //后置i++
    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);

    //+=
    StrBlobPtr& operator+=( std::size_t n);

    //-=
    StrBlobPtr& operator-=( std::size_t n);

    std::string &operator*()const
    {
        auto ret =check(curr,"increment past end of StrBlobPtr");
        return (*ret)[curr];
    }
    std::string *operator->()const
    {
        return & this->operator*();
    }
private:
    std::shared_ptr<vector<string>> check(size_t i, const string &msg) const
    {
        auto ret = wptr.lock();
        if (!ret) throw std::runtime_error("unbound StrBlobPtr");
        if (i >= ret->size()) throw std::out_of_range(msg);
        return ret;
    }
    std::weak_ptr<vector<string>> wptr;
    size_t curr;
};
    StrBlobPtr StrBlob::begin()//StrBlob的成员函数begin()；返回当前的指针
        {
         return StrBlobPtr(*this);
        }
    StrBlobPtr StrBlob::end()
        {
            return StrBlobPtr(*this, data->size());
        }
    bool operator==(const StrBlobPtr &lhs,const StrBlobPtr &rhs)
    {
         auto lit = lhs.wptr.lock();
         auto rit = rhs.wptr.lock();
         return lit==rit ? (lhs.curr == lhs.curr):false;
    }
    bool operator!=(const StrBlobPtr &lhs,const StrBlobPtr &rhs)
    {return!(lhs==rhs);}

    //前置
    StrBlobPtr& StrBlobPtr::operator++()
    {
    check(curr,"dereference past end");//先检查是否到啦文件尾部
    ++curr;
    return *this;
    }
    StrBlobPtr& StrBlobPtr::operator--()
    {
    --curr;
    check(curr,"increment past end of StrBlobPtr");
    return*this;
    }
    //后置
    StrBlobPtr StrBlobPtr::operator++(int)
    {
        StrBlobPtr ret =*this;
        ++*this;
        return ret;
    }
    StrBlobPtr StrBlobPtr::operator--(int)
    {
        StrBlobPtr ret =*this;
        --*this;
        return ret;
    }

    StrBlobPtr operator+(const StrBlobPtr& lhs,std::size_t  rhs)
    {
        StrBlobPtr ret =lhs;
        ret +=rhs;
        return ret;
    }

    StrBlobPtr operator-(const StrBlobPtr& lhs,std::size_t  rhs)
    {
        StrBlobPtr ret =lhs;
        ret -=rhs;
        return ret;
    }
    StrBlobPtr& StrBlobPtr::operator+=( std::size_t n)
    {
        curr += n;
        check(curr,"past end of StrBlobPtr");
        return *this;
    }
    StrBlobPtr& StrBlobPtr::operator-=( std::size_t n)
    {
        curr -= n;
        check(curr,"past end of StrBlobPtr");
        return *this;
    }
#endif
/**
 *
 *
    14_32
class pStrBlobPtr{

public:

  StrBlobPtr& operator*() const{

     return *p;
  }

  StrBlobPtr* operator->() const{

     return &(this->operator*());
  }
private:
  StrBlobPtr *p;
};
    */

