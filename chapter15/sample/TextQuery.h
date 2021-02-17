#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <vector>
#include <string>
#include <map>
#include <set>
#include <fstream>

using std::string;
using std::vector;
using std::map;
using std::set;
using std::ifstream;

class TextQuery 
{
public:
    // typedef to make declarations easier
    typedef vector<string>::size_type line_no;

    /* interface:
     * read_file builds internal data structures for the given file
     * run_query finds the given word and returns set of lines on which it appears
     * text_line returns a requested line from the input file
     */
    void read_file(ifstream &is) 
    {
        store_file(is);
        build_map();
    }

    set<line_no> run_query(const string&) const;
    string text_line(line_no) const;

    line_no size() const { return lines_of_text.size(); }

private:
    // utility functions used by read_file
    void store_file(ifstream&); // store input file
    void build_map(); // associated each word with a set of line numbers

    // remember the whole input file
    vector<string> lines_of_text;
    // map word to set of the lines on which it occurs
    map< string, set<line_no> > word_map;
};

#endif