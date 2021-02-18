#include <iostream>
#include "sales_item.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using kangleyu::Sales_item;
using kangleyu::isbn_mismatch;

int main()
{
    Sales_item item1, item2, sum;

    while(cin >> item1 >> item2) {
        try {
            sum = item1 + item2;
            // use sum
        } catch(const isbn_mismatch &e) {
            cerr << e.what() << ": left isbn(" << e.left << ") right isbn(" << e.right << ")" << endl;
        }
    }

}