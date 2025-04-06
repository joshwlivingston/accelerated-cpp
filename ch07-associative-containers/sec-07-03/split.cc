#include "split.h"

#include <algorithm>
#include <string>
#include <vector>

using std::find_if;
using std::isspace;
using std::string;
using std::vector;

vector<string> split(const string &str)
{
    vector<string> out;
    string::const_iterator char_start = str.begin();

    while (char_start != str.end())
    {
        // ignore leading blanks
        char_start = find_if(char_start, str.end(), is_not_space);

        if (char_start != str.end())
        {
            // find end of next word
            string::const_iterator char_end = find_if(char_start, str.end(), is_space);

            // copy the characters in [char_start, char_end)
            out.push_back(string(char_start, char_end));

            // continue scanning the string
            char_start = char_end;
        }
    }

    return out;
}

bool is_space(const char &ch)
{
    return isspace(ch);
}

bool is_not_space(const char &ch)
{
    return !isspace(ch);
}
