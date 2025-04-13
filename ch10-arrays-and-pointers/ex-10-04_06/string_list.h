#ifndef GUARD_string_list_h
#define GUARD_string_list_h

#include <istream>
#include <list>
#include <string>
#include <type_traits>

#include "algorithms.h"

class StringList
{
public:
    typedef std::string *iterator;

    StringList(std::size_t size_);

    void resize(std::size_t size_);

    iterator begin() { return list; }
    iterator end() { return list + size__; }
    std::size_t size() { return size__; }

private:
    std::string *list;
    std::size_t size__;
};

#endif
