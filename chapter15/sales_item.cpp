#include "sales_item.h"

Sales_item::Sales_item(const Item_base &item): p(item.clone()), use(new size_t(1)) {
}