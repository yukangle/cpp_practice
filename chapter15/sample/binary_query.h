#ifndef BINARYQUERY_H
#define BINARYQUERY_H

// #include "query.h"
// #include "query_base.h"
#include <iostream>
#include "query.h"

class BinaryQuery: public Query_base
{
protected:
    BinaryQuery(Query left, Query right, string op): lhs(left), rhs(right), oper(op) {
        std::cout << "constructing binary query..." << std::endl;
    }

    ostream& display(ostream &os) const {
        return os << "(" << lhs << " " << oper << " " << rhs << ")";
    }

    const Query lhs, rhs;
    const string oper;
};

#endif