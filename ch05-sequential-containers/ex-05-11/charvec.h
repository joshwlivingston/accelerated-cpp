#ifndef GUARD_charvec_h
#define GUARD_charvec_h

#include <string>
#include <vector>

typedef std::vector<char> charvec;

charvec concatenate(charvec, const charvec &);
bool isanyof(const std::string &, const charvec &);

#endif
