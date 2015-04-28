#ifndef ANDQUERY_H
#define ANDQUERY_H
#include "binaryquery.h"

class AndQuery : public BinaryQuery
{
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query& left, const Query& right):
        BinaryQuery(left,right, "&")
    {
        //std::cout << "AndQuery::AndQuery()\n";
    }
    QueryResult eval(const TextQuery &) const override;
};
inline Query operator& (const Query& lhs, const Query& rhs)
{
    Query_base* q=new AndQuery(lhs,rhs);
    return q;
}

#endif // ANDQUERY_H
