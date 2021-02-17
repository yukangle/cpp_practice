#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::ofstream;
using std::endl;

ofstream& write_file(ofstream &out, const string &str)
{
	return out << str;
}
