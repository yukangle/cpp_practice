#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>

#include "open_file.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::istringstream;
using std::runtime_error;

void print_result(vector<string>::const_iterator beg, vector<string>::const_iterator end)
{
    while(beg != end) {
        cout << *beg << " ";
        ++beg;
    }
    cout << endl;
}

bool isShorter(const string &s1, const string &s2) 
{
    return s1.size() < s2.size();
}

bool GT6(const string &s)
{
    return s.size() >= 6;
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr == 1) ? word : word + ending;
}

int main(int argc, char **argv)
{
    // 1. load the input file into words vector
    if (argc != 2) throw runtime_error("incorrect arguments");

    vector<string> words;
    ifstream infile;
    if (!open_file(infile, argv[1])) {
        throw runtime_error("invalid file");
    }

    string line;
    string word;
    while(getline(infile, line)) {
        istringstream stream(line);
        while (stream >> word) {
            words.push_back(word);
        }
    }

    cout << "Original: " << endl;
    print_result(words.begin(), words.end());

    // 2. sort words alphabetically so we can find the duplicates
    sort(words.begin(), words.end());

    // 3. remove the duplicates
    vector<string>::iterator end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());

    cout << "Sort and uniqued: " << endl;
    print_result(words.begin(), words.end());

    stable_sort(words.begin(), words.end(), isShorter);
    cout << "Stable sorted:  " << endl;
    print_result(words.begin(), words.end());

    vector<string>::size_type wc = count_if(words.begin(), words.end(), GT6);
    cout << wc << " " << make_plural(wc, "word", "s")
        << " 6 characters or longer" << endl;
    return 0;
}