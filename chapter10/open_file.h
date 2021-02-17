#include <fstream>
#include <string>

using std::string;
using std::ifstream;

ifstream& open_file(ifstream &in, const string &file)
{
	in.close();
	in.clear();

	in.open(file.c_str());
	return in;
}
