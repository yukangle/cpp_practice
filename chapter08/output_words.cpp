#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::cout;
using std::endl;

int main()
{
	ifstream input("input_file.txt");

	string line, word;
	vector<string> lines;

	while(getline(input, line)) {
		lines.push_back(line);
		cout << "[Read Line] " << line << endl;
	} 

	for(vector<string>::const_iterator it = lines.begin(); it != lines.end(); ++it) {
		istringstream line(*it);
		while(line >> word) {
			cout << "[Read Word] " << word << endl;
		}
	}

	return 0;
}
