/*
Split a string into a vector of words
*/

#include "strings.h"

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::isspace;
using std::string;
using std::vector;

/*
Separate a string by whitespace and place the contents into a new vector

Procedure:
1. Identify two indices, i and j.
    - i denotes the start of a word, j denotes whitespace.
2. Create a new string using the characters [i, j) delimts
*/
vector<string> split(
    // We are not modifying the string passed, so we use a const reference
    const string &s)
{
    // Define vector used to hold words
    vector<string> words;
    const string_size s_length = s.size();
    string_size i = 0;

    // invariant: we have processed characters [0, i)
    // i.e., we will sequence through entire string
    while (i != s_length)
    {
        // ignore leading blanks
        // invariant: characters in range [original i, current i) are all spaces
        // i.e., we are still inside the string and have not encountered a non-space
        // QUESTION: why random access here?
        while (i != s_length && isspace(s[i]))
        {
            ++i;
        }

        /*
        Now, outside of while, we know either:
            1. our character is not a space
        or
            2. we have reached the end of the string
        */

        // find end of next word
        // invariant: none of the character in the range [original j, current j) is a space
        // i.e., we are scanning the string until we find the next space character
        string_size j = i;
        while (j != s_length && !isspace(s[j]))
        {
            // if any non-whitespace characters exist, j will increment
            ++j;
        }

        // outside of this while, we know that if j increments, it no longer equal i, its starting value

        // so, this condition checks if any incrementing occurred
        // i.e. "Do any non-whitespace characters exist?"
        if (i != j)
        {
            // copy from string located at [i, j) into output vector
            words.push_back(s.substr(i, j - i));
            i = j;
        }
    }

    return words;
}

int main()
{
    string s;
    // getline() reads input until end of line is reached
    while (getline(cin, s))
    {
        vector<string> v = split(s);
        const_iter_strvec iter = v.begin();
        while(iter != v.end())
        {
            cout << *iter << endl;
            ++iter;
        }
    }

    return 0;
}
