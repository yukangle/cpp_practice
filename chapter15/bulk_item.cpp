#include "bulk_item.h"

double Bulk_item::net_price(size_t cnt) const {
    if (cnt >= quantity) {
        return cnt * (1 - discount) * price;
    } else {
        return cnt * price;
    }
}