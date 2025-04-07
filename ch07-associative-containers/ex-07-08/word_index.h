#ifndef GUARD_word_index_h
#define GUARD_word_index_h

#include <ios>
#include <map>
#include <string>
#include <vector>

#include "split.h"

typedef std::map<std::string, std::map<int, int>> WordIndex;

WordIndex build_word_index(
    std::istream &,
    void f(const std::string &, std::vector<std::string> &) = split);

#endif
