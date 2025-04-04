#include "read.h"

#include <ios>
#include <vector>

using std::istream;
using std::vector;

// Read a stream of doubles into a vector
istream &read(
    istream &stream_in,
    vector<double> &into)
{
    if (stream_in)
    {
        into.clear();

        double input_current;
        while (stream_in >> input_current)
        {
            into.push_back(input_current);
        }

        stream_in.clear();
    }
    return stream_in;
}
