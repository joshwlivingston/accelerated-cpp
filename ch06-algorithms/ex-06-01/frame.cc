/*
Framing a string
*/

#include "frame.h"

#include <string>

#include "strvec.h"

using std::string;

strvec frame(const strvec &v)
{
    const string::size_type kStringPadH = 1;
    const string::size_type kStringPadV = 0;
    const char kBorderChar = '*';
    const char kWhiteSpaceChar = ' ';

    strvec string_frame_lines;
    string::size_type maxlen = width(v);

    // create the border
    string border(maxlen + kStringPadH * 2 + 2, kBorderChar);

    // write the top border
    string_frame_lines.push_back(border);

    // create the vertical padding row
    string row_vpad_whitespace;
    string row_vpad;
    if (kStringPadV != 0)
    {
        string row_vpad_whitespace(maxlen + kStringPadH * 2, kWhiteSpaceChar);
        string row_vpad = kBorderChar + row_vpad_whitespace + kBorderChar;
    }

    // write the top vertical padding
    for (string::size_type i = 0; i != kStringPadV; ++i)
    {
        string_frame_lines.push_back(row_vpad);
    }

    // write the interior rows, centered
    for (strvec::const_iterator iter = v.begin(); iter != v.end(); ++iter)
    {
        const string::size_type line_length = iter->size();
        string::size_type whitespace_length = kStringPadH * 2 + maxlen - line_length;

        const string::size_type whitespace_side_length = whitespace_length / 2;

        string whitespace_left;
        const string whitespace_right(whitespace_side_length, kWhiteSpaceChar);
        // if line length is odd and maxlen is even, or vice a versa
        if (line_length % 2 == 0 + maxlen % 2 == 0 == 1)
        {
            string whitespace_left_(whitespace_side_length + 1, kWhiteSpaceChar);
            whitespace_left = whitespace_left_;
        }
        else
        {
            whitespace_left = whitespace_right;
        }

        const string row_interior = kBorderChar + whitespace_left + *iter + whitespace_right + kBorderChar;
        string_frame_lines.push_back(row_interior);
    }

    // write the bottom vertical padding
    for (string::size_type i = 0; i != kStringPadV; ++i)
    {
        string_frame_lines.push_back(row_vpad);
    }

    // write the bottom border
    string_frame_lines.push_back(border);

    return string_frame_lines;
}

