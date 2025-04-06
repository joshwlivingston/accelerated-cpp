#include "concat.h"

#include <numeric>
#include <stdexcept>
#include <string>
#include <vector>

using std::domain_error;
using std::reduce;
using std::string;
using std::vector;

string concat(vector<string> &v)
{
    if (v.empty())
    {
        throw domain_error("Input must have at least one element");
    }
    
    return reduce(v.begin(), v.end(), v[0], add);
}

string add(string &x, string &y)
{
    return x + y;
}
