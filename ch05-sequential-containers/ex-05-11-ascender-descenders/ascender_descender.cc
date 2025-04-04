#include "ascender_descender.h"

#include <string>

#include "charvec.h"

using std::string;

const charvec kDescenderChars = {'b', 'd', 'f', 'h', 'k', 'l', 't'};
const charvec kAscenderChars = {'g', 'j', 'p', 'q', 'y'};

bool has_ascenders_or_descenders(const string &s)
{
    return isanyof(s, concatenate(kDescenderChars, kAscenderChars));
}
