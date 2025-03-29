#ifndef GUARD_strings_h
#define GUARD_strings_h

#include <string>
#include <vector>

typedef std::string::size_type string_size;
typedef std::vector<std::string>::const_iterator const_iter_strvec;

// split.cpp
std::vector<std::string> split(const std::string &);

// frame.cpp
string_size maxwidth(const std::vector<std::string> &);
std::vector<std::string> frame(const std::vector<std::string> &);
std::vector<std::string> vcat(const std::vector<std::string> &, const std::vector<std::string> &);
std::vector<std::string> hcat(const std::vector<std::string> &, const std::vector<std::string> &);

#endif
