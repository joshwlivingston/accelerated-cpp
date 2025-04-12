/*
Accelerated C++: Section 10.3
Evaluate the size of an array
*/
#include <cstddef>
#include <iostream>

int main()
{
    double array[5];
    const std::size_t array_length = sizeof(array) / sizeof(*array);
    std::cout << "length: " << array_length << std::endl;
    return 0;
}
