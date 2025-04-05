#include "strvec.h"

#include <algorithm>
#include <string>

using std::max;
using std::string;

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

// Concatenate two vectors
strvec vcat(const strvec &top, const strvec &bottom)
{
    strvec vec_concatenated = top;
    vec_concatenated.insert(vec_concatenated.end(), bottom.begin(), bottom.end());
    return vec_concatenated;
}

/*
Element-wise concatenation of two string vectors.
Pads whitespace to ensure output strings are of equal length.
*/
strvec hcat(const strvec &left, const strvec &right)
{
    strvec vec_concatenated;
    const string::size_type left_length = left.size();
    const string::size_type right_length = right.size();
    const string::size_type max_input_length = max(left_length, right_length);
    const string::size_type max_left_string_length = width(left);
    const string::size_type max_right_string_length = width(right);

    for (string::size_type i = 0; i != max_input_length; ++i)
    {
        string string_concatenated = "";

        string::size_type rpad_length;
        if (i < left_length)
        {
            // if a string exists in left, add it to output
            string_concatenated = string_concatenated + left[i];

            // set right padding to what is left over from the left side
            rpad_length = max_left_string_length - left[i].size();
        }
        else
        {
            // if no string exists in left, set padding to entire width of left side
            rpad_length = max_left_string_length;
        }

        // add padding to output to ensure vertical alignment of RHS
        const string padding(rpad_length, ' ');
        string_concatenated = string_concatenated + padding;

        if (i < right_length)
        {
            // if a string exists at right, add it to the output
            string_concatenated = string_concatenated  + right[i];
        }

        vec_concatenated.push_back(string_concatenated);
    }

    return vec_concatenated;
}
