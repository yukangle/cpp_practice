#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() 
{
	int ia[] = {0, 1, 2, 3, 4, 5, 6 };

	int *ip = ia;
	cout << *ip << endl;

	cout << *(ia+4) << endl;
	return 0;

}
