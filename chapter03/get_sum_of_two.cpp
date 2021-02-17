#include <iostream>
#include <vector>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> numbers;
	int count;
	cout << "Enter the number of elements: " << endl;
	cin >> count;
	for (int i = 0; i < count; i++) {
		int val = rand() % 100 + 1;
		numbers.push_back(val);
	}

	cout << "Original Numbers are: " << endl;
	for (int i = 0; i < count; i++) {
		cout << numbers[i] << "	";
	}
	cout << endl;
	
	cout << "Add the sibiling two, get results: " << endl;
	for (int i = 0; i <= count - 1; i += 2) {
		if (i + 1 < count) {
			cout << numbers[i] + numbers[i+1] << "	";
		} else {
			cout << endl << "last number has no pairs: " << numbers[count - 1];
		}
	}
	cout << endl;
	return 0;
}
