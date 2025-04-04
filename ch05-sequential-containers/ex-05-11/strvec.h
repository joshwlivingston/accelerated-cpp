#ifndef GAURD_strvec_H
#define GUARD_strvec_h

#include <string>
#include <vector>

#include "charvec.h"

typedef std::vector<std::string> strvec;

// strvec.cc
strvec get_longest_strings(const strvec &);

#endif
