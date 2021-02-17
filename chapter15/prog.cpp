#include <iostream>
#include "item_base.h"
#include "bulk_item.h"

using std::cin;
using std::cout;
using std::endl;
using std::ostream;

void print_total(ostream &os, const Item_base &item, size_t n) {
    os << "ISBN: " << item.book()
        << "\tnumber sold: " << n << "\ttotal price: "
        << item.net_price(n) << endl;
}

int main()
{

    Item_base item;

    print_total(cout, item, 10);

    Item_base *p = &item;

    Bulk_item bulk;

    print_total(cout, bulk, 10);

    p = &bulk;

}