#ifndef QUERY_H
#define QUERY_H

#include<string>
#include "query_base.h"
// #include "and_query.h"
// #include "or_query.h"
// #include "not_query.h"
#include "word_query.h"

using std::string;


class Query
{
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);

public:
    Query(const string &s): q(new WordQuery(s)) {
    }

    Query(const Query &c): q(c.q), use(c.use) { ++*use; }
    ~Query() { decr_use(); }

    Query& operator=(const Query&);

    set<TextQuery::line_no> eval(const TextQuery &t) const {
        return q->eval(t);
    }
    ostream& display(ostream &os) const {
        return q->display(os);
    }

private:
    Query(Query_base *query): q(query), use(new size_t(1)) {}

    Query_base *q;
    size_t *use;
    void decr_use() {
        if ( --*use == 0)
        {
            delete q;
            delete use;
        }
        
    }
};

// inline Query operator&(const Query &lhs, const Query &rhs) {
//     return new AndQuery(lhs, rhs);
// }

// inline Query operator|(const Query &lhs, const Query &rhs) {
//     return new OrQuery(lhs, rhs);
// }

// inline Query operator~(const Query &oper) {
//     return new NotQuery(oper);
// }

inline ostream& operator<<(ostream &os, const Query &q) {
    return q.display(os);
}

#endif