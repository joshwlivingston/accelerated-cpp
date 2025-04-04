#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "url.h"

using std::back_inserter;
using std::cin;
using std::copy;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<string> urls;
    string s;
    while (cin >> s)
    {
        const vector<string> urls_from_input = find_urls(s);
        copy(urls_from_input.begin(), urls_from_input.end(), back_inserter(urls));
    }

    cout << endl
         << "URL's found:" << endl;
    for (vector<string>::const_iterator it = urls.begin(); it != urls.end(); ++it)
    {
        cout << *it << endl;
    }

    return 0;
}
