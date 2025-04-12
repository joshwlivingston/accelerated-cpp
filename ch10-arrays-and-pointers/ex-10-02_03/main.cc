#include <iostream>
#include <vector>

#include "median.h"

int main()
{
    std::cout << "Array:" << std::endl;
    static const int kInputs = 11;
    double n;
    double numbers[kInputs];
    double *begin = numbers;
    int i = 0;
    while (i != kInputs && std::cin >> numbers[i++])
        ;

    std::cout << std::endl
              << "Median: "
              << median<double *, double>(begin, begin + kInputs)
              << std::endl;

    std::cout << "Original array: " << std::endl;
    const double *end = begin + kInputs;
    while (begin != end)
        std::cout << *begin++ << std::endl;

    std::cout << "Vector:" << std::endl;
    std::vector<double> numbers_vec(kInputs);
    i = 0;
    while (i != kInputs && std::cin >> numbers_vec[i++])
        ;

    std::cout << std::endl
              << "Median: "
              << median<std::vector<double>::const_iterator, double>(
                     numbers_vec.begin(), numbers_vec.end())
              << std::endl;

    std::cout << "Original vector: " << std::endl;
    std::vector<double>::const_iterator begin_vec = numbers_vec.begin();
    while (begin_vec != numbers_vec.end())
        std::cout << *begin_vec++ << std::endl;
}
