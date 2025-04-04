#include "median.h"

#include <algorithm>
#include <stdexcept>
#include <vector>

using std::domain_error;
using std::sort;
using std::vector;

// Returns the median of a vector of doubles
double median(
    // The input vector to calculate the median of
    vector<double> vec)
{
    // The size of the input vector
    const vector<double>::size_type  vec_size = vec.size();

    if (vec_size == 0)
    {
        throw domain_error("Input to median() must be a double vector with at least one value");
    }

    // The midpoint of the input vector
    const vector<double>::size_type mid = vec_size / 2;

    sort(vec.begin(), vec.end());

    return vec_size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}
