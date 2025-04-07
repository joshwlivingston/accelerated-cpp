#ifndef GUARD_url_h
#define GUARD_url_h

#include <string>
#include <vector>

void find_urls(const std::string &, std::vector<std::string> &);
std::string::const_iterator get_url_begin(std::string::const_iterator, std::string::const_iterator);
std::string::const_iterator get_url_end(std::string::const_iterator, std::string::const_iterator);
bool is_url_char(char c);
bool is_not_url_char(char c);

#endif
