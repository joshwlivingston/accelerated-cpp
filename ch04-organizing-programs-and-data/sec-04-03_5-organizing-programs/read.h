#ifndef GUARD_read_h
#define GUARD_read_h

#include <iostream>
#include <vector>

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

#endif