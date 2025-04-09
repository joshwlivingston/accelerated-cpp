#ifndef GUARD_doublevec_h
#define GUARD_doublevec_h

// doublevec.h
#include <iostream>
#include <vector>

// doublevec.cpp
std::istream &read(std::istream &stream_in, std::vector<double> &into);

double mean(const std::vector<double> &);

#endif