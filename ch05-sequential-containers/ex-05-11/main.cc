/*
In text processing it is sometimes useful to know whether a word has any
ascenders or descenders. Ascenders are the parts of lowercase letters that
extend above the text line; in the English alphabet, the letters b, d, f, h, k
l, and t have ascenders. Similarly, the descenders are the parts of lowercase
letters that descend below the line; In English, the letters g, j, p, q, and y
have descenders. Write a program to determine whether a word has any ascenders
or descenders. Extend that program to find the longest word in the dictionary
that has neither ascenders nor descenders.
*/

#include <iostream>
#include <stdexcept>
#include <string>

#include "ascender_descender.h"
#include "strvec.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::string;

int main()
{
    strvec clean_words = {""};
    string s = "";
    while (cin >> s)
    {
        if (!has_ascenders_or_descenders(s))
        {
            clean_words.push_back(s);
        }
    }

    if (clean_words.size() == 1)
    {
        cout << "No clean words found" << endl;
        return 0;
    }

    const strvec longest_clean_word = get_longest_strings(clean_words);
    cout << endl
         << "Longest clean words:" << endl;
    for (strvec::const_iterator it = longest_clean_word.begin(); it != longest_clean_word.end(); ++it)
    {
        cout << *it << endl;
    }

    return 0;
}
