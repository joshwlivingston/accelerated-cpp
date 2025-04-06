#include <iostream>
#include <map>

#include "word_index.h"

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::vector;

int main()
{
    word_index word_index = build_word_index(cin);

    for (word_index::const_iterator it = word_index.begin(); it != word_index.end(); ++it)
    {
        cout << it->first << ":" << endl;

        for (
            map<int, int>::const_iterator word_line_count = it->second.begin();
            word_line_count != it->second.end();
            ++word_line_count)
        {
            cout << "Line " << word_line_count->first << ": " << word_line_count->second << endl;
        }
        cout << endl;
    }

    return 0;
}