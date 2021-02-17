#include <iostream>
#include "Sales_item.h"

int main()
{
	// declare variables to hold running sum and data for the next record
	Sales_item total, trans;

	// is there data to process?
	if (std::cin >> total) {
		// if so, read the transaction records
		while (std::cin >> trans) {
			if (total == trans) {
				total = total + trans;
			} else {
				std::cout << total << std::endl;
				total = trans;
			}
		}

		std::cout << total << std::endl;
	} else {
		std::cout << "no data?!" << std::endl;
		return -1;
	}
	return 0;
}
