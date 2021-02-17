#include <iostream>

int main()
{
	std::cout << "Enter two numbers: " << std::endl;

	int v1, v2;
	int lower, upper;

	std::cin >> v1 >> v2;

	if (v1 <= v2) {
		lower = v1;
		upper = v2;
	} else {
		lower = v2;
		upper = v1;
	}

	for (int val = lower; val <= upper; val++) {
		std::cout << val;
		if ( (val - lower) % 10 == 0) {
			std::cout << std::endl;
		} else {
			std::cout << "	";
		}
	}

	return 0;
}
