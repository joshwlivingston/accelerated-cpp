#include <iostream>
#include <vector>

#include "swap.h"

int main()
{
    int input;
    std::vector<int> numbers;
    std::cout << "Enter numbers:" << std::endl;
    while (std::cin >> input)
    {
        numbers.push_back(input);
    }

    std::cout << std::endl
              << "swapping first 4 with the first number in input..." << std::endl;
    for (std::vector<int>::iterator number = numbers.begin(); number != numbers.end(); ++number)
        if (*number == 4)
        {
            ex0804::swap<int>(*numbers.begin(), *number);
            break;
        }

    std::vector<int>::iterator number = numbers.begin();
    while (number != numbers.end())
        std::cout << *number++ << std::endl;

    return 0;
}