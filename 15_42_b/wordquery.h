#ifndef WORDQUERY_H
#define WORDQUERY_H

#include "query_base.h"

class WordQuery : public Query_base
{
    //! class Query uses the WordQuery constructor
    friend class Query;
    WordQuery(const std::string& s):
        query_word(s)
    {
        //std::cout << "WordQuery::WordQuery(" + s + ")\n";
    }


    //! virtuals:
    QueryResult eval(const TextQuery& t) const override
    {
        //std::cout<<"WordQuery::eval()\n";
        return t.query(query_word);
    }
    std::string rep() const override
    {
    //    std::cout << "WodQuery::rep()\n";
        return query_word;
    }


    std::string query_word;
};

#endif // WORDQUERY_H
