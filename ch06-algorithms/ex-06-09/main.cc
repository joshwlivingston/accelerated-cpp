#include <iostream>
#include <string>
#include <vector>

#include "concat.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<string> strings;
    string s;
    while (cin >> s)
    {
        strings.push_back(s);
    }

    cout << concat(strings) << endl;

    return 0;
}
