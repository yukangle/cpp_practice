#include "or_query.h"

set<TextQuery::line_no> OrQuery::eval(const TextQuery &file) const {
    // virtual calls through the Query handle to get result sets for the operands
    set<line_no> right = rhs.eval(file), ret_lines = lhs.eval(file);

    ret_lines.insert(right.begin(), right.end());
    return ret_lines;
}