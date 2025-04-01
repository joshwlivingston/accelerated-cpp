#include "strings.h"
#include "stringvec.h"

#include <stdexcept>
#include <string>
#include <vector>

using std::domain_error;
using std::max;
using std::string;
using std::vector;

/*
Element-wise concatenation of two string vectors.
Pads whitespace to ensure output strings are of equal length.
*/
vector<string> hcat(const vector<string> &left, const vector<string> &right, bool padl, bool padr)
{
    if (padl && padr)
    {
        throw domain_error("`padl` and `padr` cannot both be `true`.");
    }

    vector<string> vec_concatenated;
    const string_size left_length = left.size();
    const string_size right_length = right.size();
    const string_size max_input_length = max(left_length, right_length);
    const string_size max_left_string_length = width(left);
    const string_size max_right_string_length = width(right);

    for (string_size i = 0; i != max_input_length; ++i)
    {
        string string_concatenated = "";

        if (i < left_length)
        {
            // if a string exists in left, add it to output
            string_concatenated = string_concatenated + left[i];
        }

        if (padl || padr)
        {
            string padding = "";
            if (i < left_length)
            {
                // set right padding to what is left over from the left side
                string padding_(max_left_string_length - left[i].size(), ' ');
                padding = padding_;
            }
            else
            {
                // if no string exists in left, set padding to entire width of left side
                string padding_(max_left_string_length, ' ');
                padding = padding_;
            }

            // add padding to output to ensure vertical alignment of RHS
            if (padl)
            {
                // pad left side
                string_concatenated = padding + string_concatenated;
            }
            else
            {
                // pad right side
                string_concatenated = string_concatenated + padding;
            }
        }

        if (i < right_length)
        {
            // if a string exists at right, add it to the output
            string_concatenated = string_concatenated + right[i];
        }

        vec_concatenated.push_back(string_concatenated);
    }

    return vec_concatenated;
}

// Concatenate all strings in a vector into one string, separated by spaces
std::string hcat(const std::vector<std::string> &v)
{
    string s = "";
    for (const_iter_strvec it = v.begin(); it != v.end(); ++it)
    {
        s += *it + " ";
    }

    return s;
}

// Returns the length of the longest string in the vector
string_size width(const vector<string> &s)
{
    string_size maxlen = 0;
    const_iter_strvec iter = s.begin();
    while (iter != s.end())
    {
        maxlen = max(maxlen, iter->size());
        ++iter;
    }

    return maxlen;
}
