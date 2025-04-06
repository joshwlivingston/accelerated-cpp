#include "median.h"

#include <vector>

using std::vector;

// Returns the median of a vector of doubles
double median(
    // The input vector to calculate the median of
    std::vector<double> vec)
{
    // The size of the input vector
    const vector_size vec_size = vec.size();

    if (vec_size == 0)
    {
        throw std::domain_error("Input to median() must be a double vector with at least one value");
    }

    // The midpoint of the input vector
    const vector_size mid = vec_size / 2;

    sort(vec.begin(), vec.end());

    return vec_size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}
