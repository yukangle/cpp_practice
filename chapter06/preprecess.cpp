#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;

int main()
{
	#ifndef NDEBUG
	cerr << "starting main" << endl;
	#endif

	cout << "Program is running..." << endl;
}
