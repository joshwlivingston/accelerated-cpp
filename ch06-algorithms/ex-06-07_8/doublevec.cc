#include "doublevec.h"

#include <algorithm>
#include <numeric>
#include <ios>
#include <stdexcept>
#include <vector>

using std::accumulate;
using std::domain_error;
using std::istream;
using std::sort;
using std::vector;

// Read a stream of doubles into a vector
std::istream &read(
    std::istream &stream_in,  // Incoming data stream (e.g., `cin`)
    std::vector<double> &into // A reference to the vector to hold the doubles. Will be cleared if not-empty.
)
{
    if (stream_in) // Do not attempt to read non existent data
    {
        // Discard contents of referenced vector, if provided
        into.clear();

        double input_current;
        while (stream_in >> input_current)
        {
            into.push_back(input_current);
        }

        // reset error indications so stream may continue
        stream_in.clear();
    }
    return stream_in;
}

// Returns the median of a vector of doubles
double median(
    // The input vector to calculate the median of
    vector<double> vec)
{
    // The size of the input vector
    const vector<double>::size_type vec_size = vec.size();

    if (vec_size == 0)
    {
        throw domain_error("Input to median() must be a double vector with at least one value");
    }

    // The midpoint of the input vector
    const vector<double>::size_type mid = vec_size / 2;

    sort(vec.begin(), vec.end());

    return vec_size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

double mean(const vector<double> &vec)
{
    if (vec.size() == 0)
    {
        throw domain_error("Input must have at least one element");
    }

    return accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
}
