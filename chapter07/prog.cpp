#include <iostream>
#include "Sales_item.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	Sales_item item1, item2;
	
	item1.read_inputs(cin);
	item2.read_inputs(cin);

	item1.write_output(cout);
	item2.write_output(cout);
	return 0;
	
}
