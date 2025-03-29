/*
Framing a string
*/

#include "strings.h"

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::max;
using std::string;
using std::vector;

// Returns the length of the longest string in the vector
string_size maxwidth(const vector<string> &s)
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

vector<string> frame(const vector<string> &v)
{
    const string_size kStringPadH = 1;
    const string_size kStringPadV = 0;
    const char kBorderChar = '*';
    const char kWhiteSpaceChar = ' ';

    vector<string> string_frame_lines;
    string_size maxlen = maxwidth(v);

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
    for (string_size i = 0; i != kStringPadV; ++i)
    {
        string_frame_lines.push_back(row_vpad);
    }

    // write the interior rows, centered
    for (const_iter_strvec iter = v.begin(); iter != v.end(); ++iter)
    {
        const string_size line_length = iter->size();
        string_size whitespace_length = kStringPadH * 2 + maxlen - line_length;

        const string_size whitespace_side_length = whitespace_length / 2;

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
    for (string_size i = 0; i != kStringPadV; ++i)
    {
        string_frame_lines.push_back(row_vpad);
    }

    // write the bottom border
    string_frame_lines.push_back(border);

    return string_frame_lines;
}

// Concatenate two vectors
vector<string> vcat(const vector<string> &top, const vector<string> &bottom)
{
    vector<string> vec_concatenated = top;

    // for (const_iter_strvec it = bottom.begin(); it != bottom.end(); ++it)
    // {
    //     vec_concatenated.push_back(*it);
    // }

    // .insert() is shorthand for the above
    vec_concatenated.insert(vec_concatenated.end(), bottom.begin(), bottom.end());

    return vec_concatenated;
}

/*
Element-wise concatenation of two string vectors.
Pads whitespace to ensure output strings are of equal length.
*/
vector<string> hcat(const vector<string> &left, const vector<string> &right)
{
    vector<string> vec_concatenated;
    const string_size left_length = left.size();
    const string_size right_length = right.size();
    const string_size max_input_length = max(left_length, right_length);
    const string_size max_left_string_length = maxwidth(left);
    const string_size max_right_string_length = maxwidth(right);

    for (string_size i = 0; i != max_input_length; ++i)
    {
        string string_concatenated = "";

        string_size rpad_length;
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

int main()
{
    vector<string> strings;
    string line;
    while (getline(cin, line))
    {
        strings.push_back(line);
    }

    const vector<string> frame_lines = frame(strings);
    cout << "Framed output:" << endl;
    for (const_iter_strvec it = frame_lines.begin(); it != frame_lines.end(); ++it)
    {
        cout << *it << endl;
    }

    const vector<string> vcat_out = vcat(strings, frame_lines);
    cout << endl
         << "Vertically concatenated (1/2):" << endl;    
    for (const_iter_strvec it = vcat_out.begin(); it != vcat_out.end(); ++it)
    {
        cout << *it << endl;
    }

    const vector<string> vcat_out2 = vcat(frame_lines, strings);
    cout << endl
         << "Vertically concatenated (2/2):" << endl;    
    for (const_iter_strvec it = vcat_out2.begin(); it != vcat_out2.end(); ++it)
    {
        cout << *it << endl;
    }

    const vector<string> hcat_out = hcat(strings, frame_lines);
    cout << endl
         << "Horizontally concatenated (1/2):" << endl;    
    for (const_iter_strvec it = hcat_out.begin(); it != hcat_out.end(); ++it)
    {
        cout << *it << endl;
    }

    const vector<string> hcat_out2 = hcat(frame_lines, strings);
    cout << endl
         << "Horizontally concatenated (2/2):" << endl;    
    for (const_iter_strvec it = hcat_out2.begin(); it != hcat_out2.end(); ++it)
    {
        cout << *it << endl;
    }

    return 0;
}
