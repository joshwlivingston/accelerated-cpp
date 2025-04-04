#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "split.h"

using std::back_inserter; // <iterator>
using std::cin;
using std::copy; // <algorithm>
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<string> words;
    string s;
    while (cin >> s)
    {
        const vector<string> words_from_input = split(s);
        copy(words_from_input.begin(), words_from_input.end(), back_inserter(words));
    }

    cout << endl
         << "Words found:" << endl;
    for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it)
    {
        cout << *it << endl;
    }

    return 0;
}
