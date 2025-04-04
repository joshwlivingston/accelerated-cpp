#ifndef GUARD_strings_h
#define GUARD_strings_h

#include <string>
#include <vector>

typedef std::string::size_type string_size;

// strings.cc
std::string get_first_word(const std::string &);
std::vector<std::string> get_rotations(const std::string &);
std::vector<std::string> split(const std::string &);

#endif
