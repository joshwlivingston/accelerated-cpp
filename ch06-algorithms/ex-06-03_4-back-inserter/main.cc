#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using std::back_inserter;
using std::copy;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> u(10, 100);
    vector<int> v;
    copy(u.begin(), u.end(), back_inserter(v));

    for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << endl;
    }

    return 0;
}