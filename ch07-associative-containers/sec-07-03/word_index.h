#ifndef GUARD_word_index_h
#define GUARD_word_index_h

#include <ios>
#include <map>
#include <string>
#include <vector>

#include "split.h"

typedef std::map<std::string, std::map<int, int>> word_index;

word_index build_word_index(
    std::istream &,
    std::vector<std::string> f(const std::string &) = split);

#endif
