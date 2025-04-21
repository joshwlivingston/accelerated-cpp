#include <iostream>

#include "list.h"

int main() 
{
    typedef List<int> lst;
    // create an empty list
    // lst l_01;

    // create a list with one value
    lst l_02(4);

    // create a list of multiple values
    lst l_03(4, 20);

    lst::iterator it = l_03.begin();
    lst::const_iterator end = l_03.end();
    while (it != end)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    // create a list of multiple values and delete some
    lst l_04(8, 5);
    std::cout << "Original size: " << l_04.size() << std::endl;

    lst::iterator erase_begin = l_04.begin();
    ++erase_begin;

    lst::iterator erase_end = l_04.begin();
    ++erase_end;
    ++erase_end;
    ++erase_end;

    l_04.erase(erase_begin, erase_end);
    lst::iterator it_04 = l_04.begin();
    lst::const_iterator end_04 = l_04.end();

    std::cout << "New size: " << l_04.size() << std::endl;
    while (it_04 != end_04)
    {
        std::cout << *it_04 << std::endl;
        ++it_04;
    }

    return 0;
}
