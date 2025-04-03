#ifndef GUARD_strvec_h
#define GUARD_strvec_h

#include <string>
#include <vector>

#include "strings.h"

typedef std::vector<std::string> strvec;

// strvec.cpp
strvec center(const strvec &);
std::string center(const std::string &, const string_size &);

#endif
