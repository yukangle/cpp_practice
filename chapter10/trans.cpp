#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <stdexcept>
#include "open_file.h"

using std::cout;
using std::endl;
using std::string;
using std::map;
using std::ifstream;
using std::istringstream;
using std::runtime_error;

/*
 * A program to transform words.
 * Takes two arguments: The first is name of the word transformation file
 *                      The second is name of the input to transform
 */
int main(int argc, char **argv)
{
    // map to hold the word transformation pairs:
    // key is the word to look for in the input; value is word to use in the output
    map<string, string> trans_map;
    string key, value;

    if (argc != 3) {
        throw runtime_error("wrong number of arguments");
    }

    // open transformation file and check that open succeded
    ifstream map_file;
    if (!open_file(map_file, argv[1])) {
        throw runtime_error("no transformation file");
    }
    // read the transformation map and build the map
    while (map_file >> key >> value) {
        trans_map.insert(make_pair(key, value));
    }

    // ok, now we're ready to do the transformations
    // open the input file and check that the open succeeded
    ifstream input;
    if (!open_file(input, argv[2])) {
        throw runtime_error("no input file");
    }

    string line;
    // read the text to transform it a line at a time
    while (getline(input, line)) {
        // read the line a word at a time
        istringstream stream(line);
        string word;
        // controls whether a space is printed
        bool firstword = true;
        while (stream >> word) {
            // ok: the actual mapwork, this part is the heart of the program
            map<string, string>::const_iterator map_it = trans_map.find(word);
            // if this word is in the transformation map
            if (map_it != trans_map.end()) {
                // replace it by the transformation value in the map
                word = map_it->second;
            }
            if (firstword) {
                firstword = false;
            } else {
                // print space between words
                cout << " ";
            }
            cout << word;
        }
        // done with this line of input
        cout << endl;
    }
    return 0;
}