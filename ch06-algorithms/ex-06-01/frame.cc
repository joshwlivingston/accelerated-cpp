/*
Framing a string
*/

#include "frame.h"

#include <algorithm>
#include <iterator>
#include <string>

#include "strvec.h"

using std::back_inserter;
using std::string;
using std::transform;

static const string::size_type kStringPadH = 2;
static const string::size_type kStringPadV = 1;
static const char kBorderChar = '*';
static const char kWhiteSpaceChar = ' ';

string::size_type input_length_maximum;

strvec frame(const strvec &v)
{
    strvec string_frame_lines;
    input_length_maximum = width(v);

    // create the border
    string border(input_length_maximum + kStringPadH * 2 + 2, kBorderChar);

    // write the top border
    string_frame_lines.push_back(border);

    string row_vpad_whitespace;
    string row_vpad;
    if (kStringPadV != 0)
    {
        // create the vertical padding row
        string row_vpad_whitespace(input_length_maximum + kStringPadH * 2, kWhiteSpaceChar);
        row_vpad = kBorderChar + row_vpad_whitespace + kBorderChar;

        // write the top vertical padding
        for (string::size_type i = 0; i != kStringPadV; ++i)
        {
            string_frame_lines.push_back(row_vpad);
        }
    }

    // write the interior rows, centered
    transform(v.begin(), v.end(), back_inserter(string_frame_lines), create_frame_row_interior);

    if (kStringPadV != 0)
    {
        // write the bottom vertical padding
        for (string::size_type i = 0; i != kStringPadV; ++i)
        {
            string_frame_lines.push_back(row_vpad);
        }
    }

    // write the bottom border
    string_frame_lines.push_back(border);

    return string_frame_lines;
}

string create_frame_row_interior(const string &s)
{
    const string::size_type line_length = s.size();
    string::size_type whitespace_length = kStringPadH * 2 + input_length_maximum - line_length;

    const string::size_type whitespace_side_length = whitespace_length / 2;

    string whitespace_left;
    const string whitespace_right(whitespace_side_length, kWhiteSpaceChar);
    // if line length is odd and maxlen is even, or vice a versa
    if (line_length % 2 == 0 + input_length_maximum % 2 == 0 == 1)
    {
        string whitespace_left_(whitespace_side_length + 1, kWhiteSpaceChar);
        whitespace_left = whitespace_left_;
    }
    else
    {
        whitespace_left = whitespace_right;
    }

    return kBorderChar + whitespace_left + s + whitespace_right + kBorderChar;
}
