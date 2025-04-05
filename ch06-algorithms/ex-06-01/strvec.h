#ifndef GUARD_strvec_h
#define GUARD_strvec_h

#include <string>
#include <vector>

typedef std::vector<std::string> strvec;

// strvec.cc
std::string::size_type width(const strvec &);
strvec vcat(const strvec &, const strvec &);
strvec hcat(const strvec &, const strvec &);

std::vector<std::string> split(const std::string &);
bool is_space(const char &);
bool is_not_space(const char &);

#endif
