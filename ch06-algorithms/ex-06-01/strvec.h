#ifndef GUARD_strvec_h
#define GUARD_strvec_h

#include <string>
#include <vector>

typedef std::vector<std::string> strvec;

// strvec.cc
std::string::size_type width(const strvec &);
strvec vcat(strvec, const strvec &);
strvec hcat(const strvec &, const strvec &);
std::string concat_with_right_pad(std::string, std::string);
std::string right_pad(const std::string &, const std::string::size_type &);

std::vector<std::string> split(const std::string &);
bool is_space(const char &);
bool is_not_space(const char &);

#endif
