#ifndef DISCITEM_H
#define DISCITEM_H

#include <map>
#include "item_base.h"

using std::pair;
using std::make_pair;

class Disc_item : public Item_base
{
public:
    Disc_item(const string& book = "",
                double sales_price = 0.0,
                size_t qty = 0,
                double disc_rate = 0.0) :
                Item_base(book, sales_price), quantity(qty), discount(disc_rate) {}

    pair<size_t, double> discount_policy() const {
        return make_pair(quantity, discount);
    }

    double net_price(size_t) const = 0;
protected:
    size_t quantity;
    double discount;
};

#endif