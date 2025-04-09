#ifndef GUARD_algorithms_h
#define GUARD_algorithms_h

#include <utility>

namespace ex0802 {

/* Checks whether [begin, end) and a range starting from comparison are
   equal */
template <class ForwardIteratorInput, class ForwardIteratorComparison>
bool equal(
    ForwardIteratorInput begin,
    ForwardIteratorInput end,
    ForwardIteratorComparison comparison)
{
    while (begin != end)
        if (*begin++ != *comparison++)
            return false;
    return true;
}

/* Searches for the first occurrence of the sequence of elements
   [matches_begin, matches_end) in the range [begin, end) */
template <class ForwardIteratorInput, class ForwardIteratorMatches>
ForwardIteratorInput search(
    ForwardIteratorInput begin,
    ForwardIteratorInput end,
    ForwardIteratorMatches matches_begin,
    ForwardIteratorMatches matches_end)
{
    for (; begin != end; ++begin)
    {
        ForwardIteratorMatches match_current = matches_begin;
        while (match_current != matches_end)
            if (*begin == *match_current++)
                return begin;
    }
    return begin;
}

/* Returns an iterator to the first element in the range [begin, end) that
   is equal to match (or last if there is no such iterator) */
template <class FowardIterator, class InputValue>
FowardIterator find(
    FowardIterator begin,
    FowardIterator end,
    const InputValue &match)
{
    while (begin != end && *begin != match)
        ++begin;
    return begin;
}

/* Returns an iterator to the first element in the range [begin, end) for
   which predicate() is true (or last if there is no such iterator) */
template <class FowardIterator, class InputValue>
FowardIterator find_if(
    FowardIterator begin,
    FowardIterator end,
    bool predicate(const InputValue &))
{
    while (begin != end && !predicate(*begin))
        ++begin;
    return begin;
}

/* Copies the elements in the range, defined by [begin, end), to another range
   beginning at destination_begin (copy destination range). */
template <class ForwardIteratorInput, class ForwardIteratorDestination>
ForwardIteratorDestination copy(
    ForwardIteratorInput begin,
    ForwardIteratorInput end,
    ForwardIteratorDestination destination_begin)
{
    while (begin != end)
        *destination_begin++ = *begin++;
    return destination_begin;
}

/* Copies the elements in the range, defined by [begin, end), to another range
   beginning at destination_begin (copy destination range), omitting elements
   equal to match. */
template <
    class ForwardIteratorInput,
    class ForwardIteratorDestination,
    class InputType>
ForwardIteratorDestination remove_copy(
    ForwardIteratorInput begin,
    ForwardIteratorInput end,
    ForwardIteratorDestination destination_begin,
    const InputType &match)
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
    class ForwardIteratorInput,
    class ForwardIteratorDestination,
    class InputType>
ForwardIteratorDestination remove_copy_if(
    ForwardIteratorInput begin,
    ForwardIteratorInput end,
    ForwardIteratorDestination destination_begin,
    bool predicate(const InputType &))
{
    for (; begin != end; ++begin)
        if (!predicate(*begin))
            *destination_begin++ = *begin;
    return destination_begin;
}

/* Removes all elements that equal match from the range [begin, end) and
   returns a past-the-end iterator for the new end of the range. */
template <class ForwardIterator, class InputType>
ForwardIterator remove(
    ForwardIterator begin,
    ForwardIterator end,
    const InputType &match)
{
    ForwardIterator first_removed = find(begin, end, match);
    for (begin = first_removed; begin != end; ++begin)
        if (*begin != match)
            *first_removed++ = std::move(*begin);
    return first_removed;
}

/* Applies the given function to the the range [begin, end), and
   stores the result in an output range starting from begin_destination */
template <
    class ForwardIteratorInput,
    class ForwardIteratorDestination,
    class TypeInput,
    class TypeOutput>
ForwardIteratorDestination transform(
    ForwardIteratorInput begin,
    ForwardIteratorInput end,
    ForwardIteratorDestination begin_destination,
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
template <class ForwardIterator, class T>
ForwardIterator partition(
    ForwardIterator begin,
    ForwardIterator end,
    bool predicate(const T &))
{
    ForwardIterator first_false = find_if(begin, end, predicate);
    for (ForwardIterator current = first_false; current != end; ++current)
        if (predicate(*current))
            *first_false++ = std::move(*current);
    return first_false;
}

/* Computes the sum of the given value init and the elements in the range
   [begin, end). */
template <class ForwardIterator, class InputType>
InputType accumulate(
    ForwardIterator begin,
    ForwardIterator end,
    InputType init)
{
    while (begin != end)
        init += *begin++;
    return init;
}

} // namespace ex0802

#endif
