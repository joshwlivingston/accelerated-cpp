#include <iostream>

#include "../ch11-abstract-data-types/ex-11-08/iterator_bidirectional.h"

int main()
{
    int five = 5;
    IteratorBidirectional<int> it(five);
    IteratorBidirectional<int> *p = &it;
    std::cout << p << std::endl; // 0xf8c41ff7a0
    std::cout << *it << std::endl; // 5
    std::cout << sizeof(p) << std::endl; // 8
    std::cout << sizeof(it) << std::endl; // 24
    std::cout << sizeof(*it) << std::endl; // 4
    return 0;
}
