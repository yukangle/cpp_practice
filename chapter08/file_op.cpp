#include <iostream>
#include <fstream>
#include <vector>

using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

extern void process(string& str) {
	cout << "Got value: " << str << endl;
}

int main()
{
	vector<string> files { "input1.txt", "input2.txt", "input3.txt" };

	ifstream input;
	vector<string>::const_iterator it = files.begin();

	while(it != files.end()) {
		input.open(it->c_str());

		if(!input) {
			break;
		}
		string s;
		while(input >> s) {
			process(s);
		}

		input.close();
		input.clear();
		++it;
	}

}

