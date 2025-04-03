/*
Palindromes are words that are spelled the same right to left as left to right. Write a
program to find all the palindromes in a dictionary. Next, find the longest palindrome.
*/

#include <iostream>
#include <string>
#include <vector>

#include "palindromes.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<string> strings;
    string s;
    while(cin >> s)
    {
        strings.push_back(s);
    }

    cout << endl
         << "Longest palindromes:" << endl;
    vector<string> longest_palindromes = get_longest_palindromes(strings);
    for (vector<string>::const_iterator it = longest_palindromes.begin(); it != longest_palindromes.end(); ++it)
    {
        cout << *it << endl;
    }

    return 0;
}
