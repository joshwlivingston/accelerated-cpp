#include <iostream>
#include <string>
#include <vector>

#include "algorithms.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string x;
    vector<string> inputs;
    while (cin >> x)
        inputs.push_back(x);
    cout << endl
         << *ex0802::find<vector<string>::const_iterator, string>(inputs.begin(), inputs.end(), "j") << endl;
    return 0;
}
