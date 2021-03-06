
#ifndef MY_13_25_H
#define MY_13_25_H

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>

using std::vector; using std::string;

class StrBlobPtr;

class StrBlob {
public:
    using size_type = vector<string>::size_type;
    friend class StrBlobPtr;

    StrBlobPtr begin();
    StrBlobPtr end();

    StrBlob():data(std::make_shared<vector<string>>()) { }
    StrBlob(std::initializer_list<string> il):data(std::make_shared<vector<string>>(il)) { }
      
       StrBlob(const  StrBlob&p):data(p.data){};//拷贝构造
        
        StrBlob &operator=(const StrBlob &rhs)
        {
          auto n=rhs.data;
          data  = n;
          return *this;
        }

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

class StrBlobPtr {
public:
    StrBlobPtr():curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0):wptr(a.data), curr(sz) { }
    bool operator!=(const StrBlobPtr& p) {return p.curr != curr; }
    string& deref() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    StrBlobPtr& incr() {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }

private:
    std::shared_ptr<vector<string>> check(size_t i, const string &msg) const {
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

//因为是智能指针，所以不需要析构函数
#endif