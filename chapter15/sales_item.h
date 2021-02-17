#ifndef SALESITEM_H
#define SALESITEM_H

#include <stdexcept>
#include "item_base.h"

using std::logic_error;

// use counted handle class for the Item_base hierarchy
class Sales_item 
{
public:
    Sales_item() : p(0), use(new size_t(1)) {}
    Sales_item(const Item_base&);
    Sales_item(const Sales_item &i): p(i.p), use(i.use) { ++*use; }
    ~Sales_item() { decr_use(); }

    Sales_item& operator=(const Sales_item&);

    const Item_base *operator->() const  {
        if (p) {
            return p;
        } else {
            throw logic_error("unbound Sales_item");
        }
    }
    
    const Item_base &operator*() const {
        if (p) {
            return *p;
        } else {
            throw logic_error("unbound Sales_item");
        }
    }

private:
    // pointer to shared item
    Item_base *p;
    // pointer to shared use count
    size_t *use;

    void decr_use() {
        if (--*use == 0) {
            delete p;
            delete use;
        }
    }
};

#endif