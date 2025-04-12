/*
Accelerated C++: Section 10.1.1
Simple program that uses pointers
*/
#include <iostream>

int main()
{

    int x = 4;
    int *p = &x;                           // create p, which points to x
    std::cout << "x = " << x << std::endl; // "x = 4"
    *p = 7;                                // update value of x through p
    std::cout << "x = " << x << std::endl; // "x = 7"
    return 0;
}
