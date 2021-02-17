#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	const size_t array_size = 10;
	int ia[array_size];

	for (size_t i = 0; i != array_size; i++) {
		ia[i] = i;
	}

	for (size_t i = 0; i != array_size; i++) {
		cout << ia[i] << " ";
	}
	cout << endl;

	return 0;
}
