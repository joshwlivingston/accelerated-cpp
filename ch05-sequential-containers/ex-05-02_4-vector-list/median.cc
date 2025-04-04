#include "median.h"

#include <algorithm>
#include <stdexcept>
#include <vector>

using std::domain_error;
using std::sort;
using std::vector;

double median(vector<double> vec)
{
    const vector_size vec_size = vec.size();

    if (vec_size == 0)
    {
        throw std::domain_error("Input to median() must be a double vector with at least one value");
    }

    const vector_size mid = vec_size / 2;

    sort(vec.begin(), vec.end());

    return vec_size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}
