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
    // Incoming data stream (e.g., `cin`)
    std::istream &stream_in,
    // A reference to the vector to hold the doubles. Cleared if not-empty.
    std::vector<double> &into)
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

double mean(const vector<double> &vec)
{
    if (vec.size() == 0)
    {
        throw domain_error("Input must have at least one element");
    }

    return accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
}
