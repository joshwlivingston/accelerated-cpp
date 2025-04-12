#ifndef GUARD_median_h
#define GUARD_median_h

#include <algorithm>
#include <stdexcept>

template <class ContainerIterator, class TypeOutput>
TypeOutput median(ContainerIterator begin, ContainerIterator end)
{
    if (end == begin)
        throw std::domain_error("Empty input to median()");

    TypeOutput input[end - begin];
    TypeOutput *first = input;

    int input_size = 0;
    while (begin != end)
        input[input_size++] = *begin++;

    if (input_size == 1)
        return input[0];

    std::sort(first, first + input_size - 1);
    const TypeOutput *mid = first + input_size / 2;
    return input_size % 2 == 0 ? (*mid + mid[-1]) / 2 : *mid;
}

#endif
