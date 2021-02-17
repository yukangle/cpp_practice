#ifndef ITEMBASE_H
#define ITEMBASE_H

#include <string>

using std::string;

class Item_base
{
public:
    Item_base(const string &book = "", double sales_price = 0.0):
        isbn(book), price(sales_price) { }

    string book() const { return isbn; }

    // returns total sales price for a specified number of items
    // derived classes will override and apply different discount algorithms
    virtual double net_price(size_t n) const { return n * price; }

    virtual Item_base* clone() const { return new Item_base(*this); }

    virtual ~Item_base() { }

private:
    string isbn;

protected:
    double price;
};

#endif