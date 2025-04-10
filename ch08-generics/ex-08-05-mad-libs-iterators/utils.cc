#include "utils.h"

#include <string>

bool is_space(const char &ch)
{
    return std::isspace(ch);
}

bool is_not_space(const char &ch)
{
    return !std::isspace(ch);
}

bool is_bracket_open(const char &c)
{
    return c == '<';
}

bool is_bracket_close(const char &c)
{
    return c == '>';
}

bool is_bracketed(const std::string &s)
{
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}
