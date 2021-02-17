#include <iostream>
#include "open_file.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	ifstream input;
	string s;
	ifstream read = open_file(input, "input1.txt");

	while(!read.eof()) {
		read >> s;
		cout << s << endl;
	}
}
