#include "string.h"

String operator+(const String &lhs, const String &rhs)
{
    String out = lhs;
    out += rhs;
    return out;
}
std::istream &operator>>(std::istream &instream, String &str)
{
    str.erase();
    char c;
    while (instream.get(c) && std::isspace(c))
        ;
    if (instream)
    {
        do str.append(c);
        while (instream.get(c) && !std::isspace(c));
        if (instream)
            instream.unget();
    }
    return instream;
}
std::ostream &operator<<(std::ostream &outstream, const String &str)
{
    for (String::size_type i = 0; i != str.size(); ++i)
    {
        outstream << str[i];
    }
    return outstream;
}
