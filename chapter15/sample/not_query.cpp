#include "not_query.h"

set<TextQuery::line_no> NotQuery::eval(const TextQuery &file) const {
    set<line_no> has_val = query.eval(file);
    set<line_no> ret_lines;

    for (line_no n = 0; n != file.size(); ++n) {
        if (has_val.find(n) == has_val.end()) {
            ret_lines.insert(n);
        }
    }

    return ret_lines;
}