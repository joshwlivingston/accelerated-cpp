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
    while (it_04 != end_04)
        std::cout << *it_04++ << std::endl;

    std::cout << "New size: " << l_04.size() << std::endl;

    // create a list of multiple values and delete some
    lst l_05(3, 3);
    std::cout << "Original size: " << l_05.size() << std::endl;

    lst::iterator erase_begin_05 = l_05.begin();

    lst::iterator erase_end_05 = l_05.begin();
    ++erase_end_05;

    l_05.erase(erase_begin_05, erase_end_05);
    l_05.resize();
    lst::iterator it_05 = l_05.begin();
    lst::iterator end_05 = l_05.end();

    std::cout << "New size: " << l_05.size() << std::endl;
    while (it_05 != end_05)
        std::cout << *it_05++ << std::endl;

    l_05.insert(l_05.begin(), l_04.begin(), l_04.end());
    it_05 = l_05.begin();
    end_05 = l_05.end();
    std::cout << "New size: " << l_05.size() << std::endl;
    while (it_05 != end_05)
        std::cout << *it_05++ << std::endl;

    lst::iterator insert_begin = l_05.begin();
    ++insert_begin;
    ++insert_begin;
    ++insert_begin;
    l_05.insert(insert_begin, l_03.begin(), l_03.end(), l_03.size());
    it_05 = l_05.begin();
    end_05 = l_05.end();
    std::cout << "New size: " << l_05.size() << std::endl;
    while (it_05 != end_05)
        std::cout << *it_05++ << std::endl;

    lst::iterator erase_begin_ = l_05.begin();
    ++erase_begin_;
    ++erase_begin_;
    ++erase_begin_;
    ++erase_begin_;
    lst::iterator erase_end_ = l_05.end();
    --erase_end_;
    --erase_end_;
    l_05.erase(erase_begin_, erase_end_);
    it_05 = l_05.begin();
    end_05 = l_05.end();
    std::cout << "New size: " << l_05.size() << std::endl;
    while (it_05 != end_05)
        std::cout << *it_05++ << std::endl;
    l_05.resize();

    return 0;
}
