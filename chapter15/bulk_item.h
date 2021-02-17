#ifndef BULKITEM_H
#define BULKITEM_H

#include "disc_item.h"

// discount kicks in when a specified number of copies of same book are sold
// the discount is expressed as a fraction used to reduce the normal price
class Bulk_item: public Disc_item
{
public:
    Bulk_item(const string &book = "", double sales_price = 0.0, size_t qty = 0, double disc_rate = 0.0)
        : Disc_item(book, sales_price, qty, disc_rate) { }
    // redefines base version so as to implement bulk purchase discount policy
    double net_price(size_t) const;

    Bulk_item* clone() const { return new Bulk_item(*this); }
};

#endif

