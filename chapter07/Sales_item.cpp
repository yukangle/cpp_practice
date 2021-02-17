#include "Sales_item.h"

using std::endl;

double Sales_item::avg_price() const
{
	if (units_sold) {
		return revenue / units_sold;
	} else {
		return 0;
	}
}

