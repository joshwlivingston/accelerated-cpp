#include <iostream>
#include <map>

#include "url.h" // change 1/2: include url header from 6.1.3
#include "word_index.h"

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::vector;

int main()
{
    const WordIndex word_index = build_word_index(cin, find_urls); // change 2/2: use find_urls() instead of split()
    for (WordIndex::const_iterator it = word_index.begin(); it != word_index.end(); ++it)
    {
        cout << it->first << ":" << endl;

        map<int, int>::const_iterator word_line_count = it->second.begin();
        while (word_line_count != it->second.end())
        {
            cout << "Line " << word_line_count->first << ": " << word_line_count->second << endl;
            ++word_line_count;
        }
        cout << endl;
    }

    return 0;
}