#include "string_list.h"

StringList::StringList(std::size_t size_)
{
    size__ = size_;
    list = new std::string[size_];
}

void StringList::resize(std::size_t size_)
{
    std::string *copied = new std::string[size__];
    algo::copy<iterator, iterator>(begin(), end(), copied);
    list = new std::string[size_];
    algo::copy<iterator, iterator>(copied, copied + size__, list);
    size__ = size_;
}
