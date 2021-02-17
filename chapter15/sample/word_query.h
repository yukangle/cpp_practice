#ifndef WORDQUERY_H
#define WORDQUERY_H

#include <iostream>
#include "query.h"

using std::string;
using std::cout;
using std::endl;

class WordQuery: public Query_base 
{
    friend class Query;
    WordQuery(const string &s): query_word(s) {
        cout << "constructing WordQuery" << endl;
    }

    set<line_no> eval(const TextQuery &t) const {
        return t.run_query(query_word);
    }

    ostream& display(ostream &os) const {
        return os << query_word;
    }

    string query_word;
};

#endif