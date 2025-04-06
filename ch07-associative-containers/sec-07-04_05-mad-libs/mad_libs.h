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
void r_generate_mad_libs(const MadLibsRules &, const std::string &, MadLibs &);

// utilities
bool is_bracketed(const std::string &s);

#endif
