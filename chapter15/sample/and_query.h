#ifndef ANDQUERY_H
#define ANDQUERY_H

#include <iostream>
#include "query.h"
#include "binary_query.h"

class AndQuery: public BinaryQuery 
{
    friend Query operator&(const Query&, const Query&);

    AndQuery(Query left, Query right): BinaryQuery(left, right, "&") {
        std::cout << "constructing add query..." << std::endl;
     }

    set<line_no> eval(const TextQuery&) const;
};

inline Query operator&(const Query &lhs, const Query &rhs) {
    std::cout << "invoking and operator..." << std::endl;
    return new AndQuery(lhs, rhs);
}

#endif