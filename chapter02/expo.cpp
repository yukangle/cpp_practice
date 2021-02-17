#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() 
{
	int base, expo;
	cout << "Enter the base " << endl;
	cin >> base;
	cout << "Enter the exponent " << endl;
	cin >> expo;

	int result = 1;

	for (int i = 1; i <= expo; i++) {
		result *= base;
	}

	cout << "The result is " << result << endl;
	return 0;
}
