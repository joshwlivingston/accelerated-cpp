#ifndef GUARD_median_h // name of preprocessor variable to store defined program in. first line (even before comments)
#define GUARD_median_h // if defined, file will not be re-compile each time it is loaded

// median.h
#include <vector>

// The size of a vector of doubles
typedef std::vector<double>::size_type vector_size;

double median(std::vector<double> vec);

#endif
