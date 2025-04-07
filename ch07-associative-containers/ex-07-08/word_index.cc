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

/*
Given an input stream of strings, returns an index showing the occurrences of each word by line.abort
*/
WordIndex build_word_index(
    istream &in,
    void get_words(const string &, vector<string> &))
{
    // initialize output index
    WordIndex out;

    // read each line in input stream
    string line;
    int line_number = 0;
    while (getline(in, line))
    {
        ++line_number;

        // iterate through all words identified in line;
        vector<string> words;
        get_words(line, words);
        for (vector<string>::const_iterator word = words.begin(); word != words.end(); ++word)
        {
            // increment entry for that word on that line
            ++out[*word][line_number];
        }
    }

    return out;
}
