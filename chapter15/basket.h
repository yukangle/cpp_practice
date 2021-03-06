#ifndef BASKET_H
#define BASKET_H

#include <set>

#include "sales_item.h"

using std::multiset;

inline bool compare(const Sales_item &lhs, const Sales_item &rhs) {
    return lhs->book() < rhs->book();
}

class Basket
{
    typedef bool (*Comp)(const Sales_item&, const Sales_item&);
public:
    typedef multiset<Sales_item, Comp> set_type;
    typedef set_type::size_type size_type;
    typedef set_type::const_iterator const_iter;

    Basket(): items(compare) { }

    void add_item(const Sales_item &item) {
        items.insert(item);
    }

    size_type size(const Sales_item &item) const {
        return items.count(item);
    }

    double total() const;

private:
    multiset<Sales_item, Comp> items;
};

#endif