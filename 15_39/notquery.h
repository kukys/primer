#ifndef NOTQUERY_H
#define NOTQUERY_H
#include "query_base.h"
#include "query.h"
class NotQuery : public Query_base
{
    friend Query operator~(const Query& operand);
    NotQuery(const Query& q): query(q)
    {
        std::cout << "NotQuery::NotQuery()\n";
    }

    //! virtuals:
    std::string rep() const override
    {
        std::cout << "NotQuery::rep()\n";
        return "~(" + query.rep() + ")";
    }

    QueryResult eval(const TextQuery &) const override;

    Query query;
};

inline Query operator~(const Query& operand)
{
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}

#endif // NOTQUERY_H
