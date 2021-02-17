#ifndef NOTQUERY_H
#define NOTQUERY_H

#include "query.h"
// #include "query_base.h"



class NotQuery: public Query_base
{
    friend Query operator~(const Query &);
    NotQuery(Query q): query(q) {}

    set<line_no> eval(const TextQuery&) const;
    ostream& display(ostream &os) const {
        return os << "~(" << query << ")";
    }

    const Query query;
};

inline Query operator~(const Query &oper) {
    return new NotQuery(oper);
}

#endif