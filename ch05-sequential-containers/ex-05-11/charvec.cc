#include "charvec.h"

#include <string>

using std::isspace;
using std::string;

charvec concatenate(charvec x, const charvec &y)
{
    x.insert(x.end(), y.begin(), y.end());
    return x;
}

bool isanyof(const string &s, const charvec &elements)
{
    for (string::const_iterator s_char = s.begin(); s_char != s.end(); ++s_char)
    {
        for (charvec::const_iterator elem = elements.begin(); elem != elements.end(); ++elem)
        {
            if (*s_char == *elem)
            {
                return true;
            }
        }
    }
    return false;
}
