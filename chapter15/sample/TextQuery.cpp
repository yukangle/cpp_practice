#include <fstream>
#include <sstream>
#include <stdexcept>
#include "TextQuery.h"

using std::ifstream;
using std::istringstream;
using std::out_of_range;

static const string REMOVE_LST = ";.!,\"\'\t\b\v\f\r";

string& ltrim(string &str, const string &chars = REMOVE_LST) {
    str.erase(0, str.find_first_not_of(chars));
    return str;
}

string& rtrim(string &str, const string &chars = REMOVE_LST) {
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}

string& trim(string &str, const string &chars = REMOVE_LST) {
    return ltrim(rtrim(str, chars), chars);
}

void TextQuery::store_file(ifstream &is)
{
    string textline;
    while (getline(is, textline)) {
        lines_of_text.push_back(textline);
    }
}

void TextQuery::build_map()
{
    for (line_no line_num = 0; line_num != lines_of_text.size(); ++line_num) {
        istringstream line(lines_of_text[line_num]);
        string word;
        while (line >> word) {
            word = trim(word);
            word_map[word].insert(line_num);
        }
    }
}

set<TextQuery::line_no> TextQuery::run_query(const string &query_word) const{
    map<string, set<line_no> >::const_iterator loc = word_map.find(query_word);

    if (loc == word_map.end()) return set<line_no>();
    else return loc->second;
}

string TextQuery::text_line(line_no line) const
{
    if (line < lines_of_text.size()) return lines_of_text[line];
    throw out_of_range("line number out of range");
}