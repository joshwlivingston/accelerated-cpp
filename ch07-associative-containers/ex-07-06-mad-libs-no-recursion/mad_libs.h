#ifndef GUARD_mad_libs_h
#define GUARD_mad_libs_h

#include <iostream>
#include <map>
#include <string>
#include <vector>

typedef std::vector<std::string> MadLibs;

typedef std::string rule;
typedef std::vector<rule> rules;
typedef std::map<std::string, rules> MadLibsRules;

void read(std::istream &, MadLibsRules &);
MadLibs generate_mad_libs(const MadLibsRules &);

// utilities
bool is_bracket_opener(char);
bool is_bracket_closer(char);
bool is_bracketed(const std::string &s);

#endif
