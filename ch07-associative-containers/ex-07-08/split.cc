#include "split.h"

#include <algorithm>
#include <string>
#include <vector>

using std::find_if;
using std::isspace;
using std::string;
using std::vector;

void split(
    const string &str,
    vector<string> &result)
{
    string::const_iterator char_start = str.begin();

    while (char_start != str.end())
    {
        char_start = find_if(char_start, str.end(), is_not_space);
        if (char_start != str.end())
        {
            string::const_iterator char_end = find_if(char_start, str.end(), is_space);
            result.push_back(string(char_start, char_end));
            char_start = char_end;
        }
    }
}

/*
Read a string into provided map.

The first word in string is the key.

If `separate_into_words` is true (the default), the remaining words are appended
to the vector in the map one word at a time.

If `separate_into_words` is false, the entire string (less the key) is appended
the the map's vector as one string.
*/
void split(
    const std::string &str,
    std::map<std::string, std::vector<std::string>> &result,
    const bool separate_into_words)
{
    // ignore leading blanks
    const string::const_iterator char_start_key = find_if(str.begin(), str.end(), is_not_space);

    if (char_start_key != str.end())
    {
        // identify first word: [char_start_key, char_end_key)
        const string::const_iterator char_end_key = find_if(char_start_key, str.end(), is_space);
        const string first_word(char_start_key, char_end_key);
        if (separate_into_words)
        {
            split(str, result[first_word]);
        }
        else
        {
            // populate map with rest of string, after leading whitespace
            const string::const_iterator char_start_entry = find_if(char_end_key, str.end(), is_not_space);
            result[first_word].push_back(string(char_start_entry, str.end()));
        }
    }
}

bool is_space(const char &ch)
{
    return isspace(ch);
}

bool is_not_space(const char &ch)
{
    return !isspace(ch);
}
