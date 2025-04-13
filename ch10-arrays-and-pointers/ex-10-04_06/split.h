#ifndef GUARD_split_h
#define GUARD_split_h

#include <string>

#include "algorithms.h"

bool is_space(const char &ch) { return isspace(ch); }
bool is_not_space(const char &ch) { return !isspace(ch); }

template <class OutputIterator>
void split(const std::string &str, OutputIterator result)
{
    std::string::const_iterator char_start = str.begin();
    while (char_start != str.end())
    {
        char_start = algo::find_if<std::string::const_iterator, char>(
            char_start, str.end(), is_not_space);
        if (char_start != str.end())
        {
            std::string::const_iterator char_end = algo::find_if<
                std::string::const_iterator, char>(
                char_start, str.end(), is_space);
            *result++ = std::string(char_start, char_end);
            char_start = char_end;
        }
    }
}

#endif
