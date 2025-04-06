/*
As a simple example, think about how we might count the number of times that each distinct
word occurs in our input.
*/
#include <iostream>
#include <map>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;

int main()
{
    string s;
    map<string, int> counts;
    while (cin >> s)
    {
        ++counts[s];
    }

    for (map<string, int>::const_iterator it = counts.begin(); it != counts.end(); ++it)
    {
        cout << it->first << ": " << it->second << endl;
    }

    return 0;
}
