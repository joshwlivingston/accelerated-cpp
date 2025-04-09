#ifndef GUARD_median_h
#define GUARD_median_h

#include <algorithm>
#include <stdexcept>
#include <vector>

template <class T>
T median(
    typename std::vector<T>::iterator begin,
    typename std::vector<T>::iterator end)
{
    const typename std::vector<T>::size_type vec_size = end - begin;
    if (vec_size == 0)
    {
        throw std::domain_error("Empty input to median()");
    }
    else if (vec_size == 1)
    {
        return *begin;
    }

    std::sort(begin, end);
    typename std::vector<T>::iterator mid = begin + vec_size / 2;
    return vec_size % 2 == 0 ? (*mid + *(mid - 1)) / 2 : *mid;
}

#endif
