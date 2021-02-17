#ifndef SALESITEM_H
#define SALESITEM_H

#include <stdexcept>
#include "handle.h"
#include "item_base.h"

using std::logic_error;

// use counted handle class for the Item_base hierarchy
class Sales_item 
{
public:
    Sales_item() : h() {}
    Sales_item(const Item_base &item): h(item.clone()) {}

    const Item_base *operator->() const  {
        return h.operator->();
    }
    
    const Item_base &operator*() const {
        return *h;
    }

private:
    Handle<Item_base> h;
};

#endif