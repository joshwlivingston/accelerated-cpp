/*
>Extend the program from §7.2/124 to produce its output sorted by occurrence count. That
>is, the output should group all the words that occur once, followed by those that occur twice,
>and so on.

We add a second map creation, after reading the input, to group the words by occurence count.
*/

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::sort;
using std::string;
using std::vector;

int main()
{
    string s;
    map<string, int> counts;
    while (cin >> s)
    {
        ++counts[s];
    }

    map<int, vector<string>> occurrence_counts;
    // group by occurrence count
    for (map<string, int>::const_iterator it = counts.begin(); it != counts.end(); ++it)
    {
        occurrence_counts[it->second].push_back(it->first);
    }

    for (map<int, vector<string>>::const_iterator it = occurrence_counts.begin(); it != occurrence_counts.end(); ++it)
    {
        cout << it->first << ": ";
        vector<string>::const_iterator ij = it->second.begin();
        cout << *ij;
        ++ij;
        while (ij != it->second.end())
        {
            cout << ", " << *ij;
            ++ij;
        }
        cout << endl;
    }

    return 0;
}
