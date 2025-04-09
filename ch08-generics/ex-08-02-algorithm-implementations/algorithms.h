#ifndef GUARD_algorithms_h
#define GUARD_algorithms_h

#include <utility>

namespace ex0802 {

/* Checks whether [begin, end) and a range starting from comparison are
   equal */
template <class InputIteratorInput, class InputIteratorComparison>
bool equal(
    InputIteratorInput begin,
    InputIteratorInput end,
    InputIteratorComparison comparison)
{
    while (begin != end)
        if (*begin++ != *comparison++)
            return false;
    return true;
}

/* Searches for the first occurrence of the sequence of elements
   [matches_begin, matches_end) in the range [begin, end) */
template <class InputIteratorInput, class InputIteratorMatches>
InputIteratorInput search(
    InputIteratorInput begin,
    InputIteratorInput end,
    InputIteratorMatches matches_begin,
    InputIteratorMatches matches_end)
{
    for (; begin != end; ++begin)
    {
        InputIteratorMatches match_current = matches_begin;
        while (match_current != matches_end)
            if (*begin == *match_current++)
                return begin;
    }
    return begin;
}

/* Returns an iterator to the first element in the range [begin, end) that
   is equal to match (or last if there is no such iterator) */
template <class InputIteratorInput, class TypeInput>
InputIteratorInput find(
    InputIteratorInput begin,
    InputIteratorInput end,
    const TypeInput &match)
{
    while (begin != end && *begin++ != match);
    return begin;
}

/* Returns an iterator to the first element in the range [begin, end) for
   which predicate() is true (or last if there is no such iterator) */
template <class InputIteratorInput, class TypeInput>
InputIteratorInput find_if(
    InputIteratorInput begin,
    InputIteratorInput end,
    bool predicate(const TypeInput &))
{
    while (begin != end && !predicate(*begin++));
    return begin;
}

/* Copies the elements in the range, defined by [begin, end), to another range
   beginning at destination_begin (copy destination range). */
template <class InputIteratorInput, class OutputIteratorDestination>
OutputIteratorDestination copy(
    InputIteratorInput begin,
    InputIteratorInput end,
    OutputIteratorDestination destination_begin)
{
    while (begin != end)
        *destination_begin++ = *begin++;
    return destination_begin;
}

/* Copies the elements in the range, defined by [begin, end), to another range
   beginning at destination_begin (copy destination range), omitting elements
   equal to match. */
template <
    class InputIteratorInput,
    class OutputIteratorDestination,
    class TypeInput>
OutputIteratorDestination remove_copy(
    InputIteratorInput begin,
    InputIteratorInput end,
    OutputIteratorDestination destination_begin,
    const TypeInput &match)
{
    for (; begin != end; ++begin)
        if (*begin != match)
            *destination_begin++ = *begin;
    return destination_begin;
}

/* Copies the elements in the range, defined by [begin, end), to another range
   beginning at destination_begin (copy destination range), omitting elements
   for which predicate() is true. */
template <
    class InputIteratorInput,
    class OutputIteratorDestination,
    class TypeInput>
OutputIteratorDestination remove_copy_if(
    InputIteratorInput begin,
    InputIteratorInput end,
    OutputIteratorDestination destination_begin,
    bool predicate(const TypeInput &))
{
    for (; begin != end; ++begin)
        if (!predicate(*begin))
            *destination_begin++ = *begin;
    return destination_begin;
}

/* Removes all elements that equal match from the range [begin, end) and
   returns a past-the-end iterator for the new end of the range. */
template <class ForwardIteratorInput, class TypeInput>
ForwardIteratorInput remove(
    ForwardIteratorInput begin,
    ForwardIteratorInput end,
    const TypeInput &match)
{
    ForwardIteratorInput first_removed = ex0802::find(begin, end, match);
    for (begin = first_removed; begin != end; ++begin)
        if (*begin != match)
            *first_removed++ = std::move(*begin);
    return first_removed;
}

/* Applies the given function to the the range [begin, end), and
   stores the result in an output range starting from begin_destination */
template <
    class InputIteratorInput,
    class OutputIteratorDestination,
    class TypeInput,
    class TypeOutput>
OutputIteratorDestination transform(
    InputIteratorInput begin,
    InputIteratorInput end,
    OutputIteratorDestination begin_destination,
    TypeOutput transform_function(const TypeInput &))
{
    while (begin != end)
        *begin_destination++ = transform_function(*begin++);
    return begin_destination;
}

/* Reorders the elements in the range [begin, end) in such a way that all
   elements for which the predicate p returns true precede all elements for
   which predicate() returns false. Relative order of the elements is not
   preserved. */
template <class ForwardIteratorInput, class TypeInput>
ForwardIteratorInput partition(
    ForwardIteratorInput begin,
    ForwardIteratorInput end,
    bool predicate(const TypeInput &))
{
    ForwardIteratorInput true_partition_end = ex0802::find_if(begin, end, predicate);
    for (begin = true_partition_end; begin != end; ++begin)
        if (predicate(*begin))
            std::swap(*true_partition_end++, *begin);
    return true_partition_end;
}

/* Computes the sum of the given value init and the elements in the range
   [begin, end). */
template <class InputIteratorInput, class TypeInput>
TypeInput accumulate(
    InputIteratorInput begin,
    InputIteratorInput end,
    TypeInput init)
{
    while (begin != end)
        init += *begin++;
    return init;
}

} // namespace ex0802

#endif
