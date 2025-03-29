#ifndef GUARD_read_h
#define GUARD_read_h

#include <iostream>
#include <vector>

// Read a stream of doubles into a vector
std::istream &read(std::istream &stream_in, std::vector<double> &into);

#endif