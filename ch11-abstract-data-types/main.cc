#include <iostream>

#include "vec.h"

int main()
{
    double n;
    Vec<double> numbers;
    while (std::cin >> n)
        numbers.push_back(n);

    std::cout << std::endl
              << "Output:" << std::endl;
    Vec<double>::const_iterator current = numbers.begin();
    while (current != numbers.end())
        std::cout << *current++ << std::endl;
    return 0;
}
