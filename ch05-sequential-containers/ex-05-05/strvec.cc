/*
Split a string into a vector of words
*/

#include "strvec.h"

#include <algorithm>
#include <string>

#include "strings.h"

using std::max;
using std::string;

/*
Returns a picture in which all the lines of the original picture are padded out to their
full width, and the padding is as evenly divided as possible between the left and
right sides of the picture.
*/
strvec center(const strvec &v)
{
    const string_size output_width = width(v);

    strvec out;
    for (strvec::const_iterator line = v.begin(); line != v.end(); ++line)
    {
        out.push_back(center(*line, output_width));
    }

    return out;
}

/*
Centers a string given a width to center in

If length of `s` is even and `output_width` is odd or vice a versa, 
the centered line will be shifted left by one character, and off 
center by one half character.
*/
string center(const string &s, const string_size &output_width)
{
    const string padding_left((output_width - s.size()) / 2, ' ');
    return padding_left + s;
}

// Returns the length of the longest string in the vector
string_size width(const strvec &s)
{
    string_size maxlen = 0;
    for (strvec::const_iterator iter = s.begin(); iter != s.end(); ++iter)
    {
        maxlen = max(maxlen, iter->size());
    }

    return maxlen;
}
