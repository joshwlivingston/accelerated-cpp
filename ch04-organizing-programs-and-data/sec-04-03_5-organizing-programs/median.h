#ifndef GUARD_median_h // name of preprocessor variable to store defined program in. first line (even before comments)
#define GUARD_median_h // if defined, file will not be re-compile each time it is loaded

// median.h
#include <algorithm>
#include <stdexcept>
#include <vector>

/*
In general, header files should declare only names that are necessary.

If a using declaration is included in a header file, all users of that header
file get a using declaration whether desired or not.
*/

// The size of a vector of doubles
typedef std::vector<double>::size_type vector_size;

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

#endif
