#ifndef GUARD_stringvec_h
#define GUARD_stringvec_h

#include "strings.h"

#include <string>
#include <vector>

typedef std::vector<std::string>::size_type stringvec_size;
typedef std::vector<std::string>::const_iterator const_iter_strvec;

// stringvec.cc
string_size width(const std::vector<std::string> &);
std::vector<std::string> hcat(const std::vector<std::string> &, const std::vector<std::string> &, bool, bool);
std::string hcat(const std::vector<std::string> &);

#endif
