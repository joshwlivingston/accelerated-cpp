#ifndef GUARD_split_h
#define GUARD_split_h

#include <map>
#include <vector>
#include <string>

void split(
    const std::string &,
    std::vector<std::string> &);

void split(
    const std::string &,
    std::map<std::string, std::vector<std::string>> &,
    const bool separate_into_words = true);

// utilities
bool is_space(const char &);
bool is_not_space(const char &);

#endif
