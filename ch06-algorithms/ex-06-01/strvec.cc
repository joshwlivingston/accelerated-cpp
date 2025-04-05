#include "strvec.h"

#include <algorithm>
#include <iterator>
#include <string>

using std::back_inserter;
using std::copy;
using std::max;
using std::string;
using std::transform;

// Returns the length of the longest string in the vector
string::size_type width(const strvec &s)
{
    string::size_type maxlen = 0;
    strvec::const_iterator iter = s.begin();
    while (iter != s.end())
    {
        maxlen = max(maxlen, iter->size());
        ++iter;
    }

    return maxlen;
}

// Concatenate two vectors. Copies the first input and appends second input to it
strvec vcat(strvec top, const strvec &bottom)
{
    copy(bottom.begin(), bottom.end(), back_inserter(top));
    return top;
}

string::size_type left_side_width;

/*
Element-wise concatenation of two string vectors.
Right pads left side to ensure output strings are vertically aligned.
*/
strvec hcat(const strvec &left, const strvec &right)
{
    const strvec::size_type longest_input = max(left.size(), right.size());

    strvec left_ = left;
    strvec right_ = right;
    if (right.size() == longest_input)
    {
        const strvec left_padding = strvec(longest_input - left.size(), "");
        copy(left_padding.begin(), left_padding.end(), back_inserter(left_));
    }
    else
    {
        const strvec right_padding = strvec(longest_input - right.size(), "");
        copy(right_padding.begin(), right_padding.end(), back_inserter(right_));
    }

    left_side_width = width(left);

    strvec out;
    transform(left_.begin(), left_.end(), right_.begin(), back_inserter(out), concat_with_right_pad);

    return out;
}

string concat_with_right_pad(string l, string r)
{
    return right_pad(l, left_side_width) + r;
}

string right_pad(const string &s, const string::size_type &out_length)
{
    return s + string(out_length - s.size(), ' ');
}
