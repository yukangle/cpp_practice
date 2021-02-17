#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::iostream;
using std::runtime_error;

int main()
{
	int ival;
	while(cin >> ival, !cin.eof()) {
		if(cin.bad()) {
			throw runtime_error("IO stream corrupted");
		}
		if(cin.fail()) {
			cerr << "bad data, try again";
			cin.clear(iostream::failbit);
			continue;
		}
		cout << "OK" << endl;
	}
}
