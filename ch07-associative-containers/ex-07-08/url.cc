#include "url.h"

#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

using std::find;
using std::find_if;
using std::isalnum; // <cctype>
using std::isalpha; // <cctype>
using std::search;
using std::string;
using std::vector;

void find_urls(const string &s, vector<string> &result)
{
    const string::const_iterator input_end = s.end();
    string::const_iterator current_char = s.begin();
    while (current_char != input_end)
    {
        current_char = get_url_begin(current_char, input_end);

        if (current_char != input_end)
        {
            string::const_iterator url_end = get_url_end(current_char, input_end);
            result.push_back(string(current_char, url_end));
            current_char = url_end;
        }
    }
}

string::const_iterator get_url_begin(string::const_iterator string_start, string::const_iterator string_end)
{
    static const string kURLSep = "://";

    // look for URL starting characters
    string::const_iterator url_sep_begin = string_start;
    while ((url_sep_begin = search(url_sep_begin, string_end, kURLSep.begin(), kURLSep.end())) != string_end)
    {
        if (url_sep_begin != string_start && url_sep_begin + kURLSep.size() != string_end)
        {
            // if we have identified a URLSep not at either the start or end of the string

            // decrement the iterator to identify the start of the protocol
            // start:  "the url is https-->:<--//www.someurl.com"
            // end: "the url is -->h<--ttps://www.someurl.com"
            string::const_iterator url_begin = url_sep_begin;
            while (url_begin != string_start && isalpha(url_begin[-1]))
            {
                --url_begin;
            }

            if (url_begin != url_sep_begin && is_url_char(url_sep_begin[kURLSep.size()]))
            {
                return url_begin;
            }
        }

        // if not valid, continue scanning the string for a URL sep
        url_sep_begin += kURLSep.size();
    }

    return string_end;
}

string::const_iterator get_url_end(string::const_iterator b, string::const_iterator e)
{
    return find_if(b, e, is_not_url_char);
}

bool is_not_url_char(char c)
{
    return !is_url_char(c);
}

bool is_url_char(char c)
{
    static const string url_ch = "~;/?:@=&$-_.+!*'(),";
    return isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end();
}
