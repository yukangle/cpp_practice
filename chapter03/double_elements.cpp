#include <iostream>
#include <vector>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	cout << "Generating 10 random numbers as below:" << endl;
	vector<int> numbers;

	for (int i = 0; i < 10; i++) {
		int val = rand() % 100 + 1;
		numbers.push_back(val);
		cout << val << " ";
	}
	cout << endl;

	for (vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); iter++) {
		*iter *= 2;
	}

	cout << "Doubled for the values of numbers, got results: " << endl;

	for (vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
	return 0;
}
