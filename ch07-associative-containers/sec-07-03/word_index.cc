#include "word_index.h"

#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::getline;
using std::istream;
using std::map;
using std::string;
using std::vector;

word_index build_word_index(
    istream &in,
    vector<string> get_words(const string &))
{
    string line;
    int line_number = 0;
    map<string, map<int, int>> out;

    while (getline(in, line))
    {
        ++line_number;

        vector<string> words = get_words(line);

        for (vector<string>::const_iterator word = words.begin(); word != words.end(); ++word)
        {
            ++out[*word][line_number];
        }
    }

    return out;
}
