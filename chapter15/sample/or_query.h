#ifndef ORQUERY_H
#define ORQUERY_H

#include "query.h"
#include "binary_query.h"

class OrQuery: public BinaryQuery 
{
    friend Query operator|(const Query&, const Query&);

    OrQuery(Query left, Query right): BinaryQuery(left, right, "|") { }

    set<line_no> eval(const TextQuery&) const;
};

inline Query operator|(const Query &lhs, const Query &rhs) {
    return new OrQuery(lhs, rhs);
}



#endif