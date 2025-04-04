#ifndef GUARD_permuted_index_h
#define GUARD_permuted_index_h

#include "strings.h"

#include <string>
#include <vector>

struct PermutedIndexEntry {
    std::vector<std::string> word_list;
    std::vector<std::string> index_list;
};

struct PermutedIndex {
    std::vector<PermutedIndexEntry> index_entries;
    string_size max_index_width = 0;
};

// permuted_index.cc
PermutedIndex get_permuted_index(const std::vector<std::string> &);
bool compare(const PermutedIndexEntry &, const PermutedIndexEntry &);
std::vector<std::string> hcat(PermutedIndex &, const std::string &);

#endif
