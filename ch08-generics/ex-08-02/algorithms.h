#ifndef GUARD_algorithms_h
#define GUARD_algorithms_h

#include <utility>

namespace ex0802 {

/* Checks whether [begin, end) and a range starting from comparison are
   equal */
template <class input_iter_1, class input_iter_2>
bool equal(
    input_iter_1 begin,
    input_iter_1 end,
    input_iter_2 comparison)
{
    while (begin != end)
        if (*begin++ != *comparison++)
            return false;
    return true;
}

/* Searches for the first occurrence of the sequence of elements
   [matches_begin, matches_end) in the range [begin, end) */
template <class input_iter, class matches_iter>
input_iter search(
    input_iter begin,
    input_iter end,
    matches_iter matches_begin,
    matches_iter matches_end)
{
    while (begin != end)
    {
        matches_iter match_current = matches_begin;
        while (match_current != matches_end)
            if (*begin == *match_current++)
                break;
        ++begin;
    }
    return begin;
}

/* Returns an iterator to the first element in the range [begin, end) that
   is equal to match (or last if there is no such iterator) */
template <class input_iter, class input_val>
input_iter find(input_iter begin, input_iter end, const input_val &match)
{
    while (begin != end && *begin != match)
        ++begin;
    return begin;
}

/* Returns an iterator to the first element in the range [begin, end) for
   which predicate() is true (or last if there is no such iterator) */
template <class input_iter, class input_val>
input_iter find_if(input_iter begin, input_iter end, bool predicate(input_val))
{
    while (begin != end && !predicate(*begin))
    {
        ++begin;
    }
    return begin;
}

/* Copies the elements in the range, defined by [begin, end), to another range
   beginning at destination_begin (copy destination range). */
template <class source_iter, class destination_iter>
destination_iter copy(
    source_iter begin,
    source_iter end,
    destination_iter destination_begin)
{
    while (begin != end)
    {
        destination_begin = begin;
        ++begin;
        ++destination_begin;
    }
    return destination_begin;
}

/* Copies the elements in the range, defined by [begin, end), to another range
   beginning at destination_begin (copy destination range), omitting elements
   equal to match. */
template <class source_iter, class source_val, class destination_iter>
destination_iter remove_copy(
    source_iter begin,
    source_iter end,
    destination_iter destination_begin,
    const source_val &match)
{
    while (begin != end)
    {
        if (begin != match)
        {
            destination_begin = begin;
            ++destination_begin;
        }
        ++begin;
    }
    return destination_begin;
}

/* Copies the elements in the range, defined by [begin, end), to another range
   beginning at destination_begin (copy destination range), omitting elements
   for which predicate() is true. */
template <class source_iter, class source_val, class destination_iter>
destination_iter remove_copy_if(
    source_iter begin,
    source_iter end,
    destination_iter destination_begin,
    bool predicate(const source_val &))
{
    while (begin != end)
    {
        if (!predicate(begin))
        {
            destination_begin = begin;
            ++destination_begin;
        }
        ++begin;
    }
    return destination_begin;
}

// /* Removes all elements that equal match from the range [begin, end) and
//    returns a past-the-end iterator for the new end of the range. */
// template <class ForwardIterator, class T>
// ForwardIterator remove(
//     ForwardIterator begin,
//     ForwardIterator end,
//     const T &match)
// {
//     typename ForwardIterator first_removed = find(begin, end, match);
//     for (begin = first_removed; begin != end; ++begin)
//         if (*begin != match)
//             *first_removed++ = std::move(*begin);
//     return first_removed;
// }

// /* Reorders the elements in the range [begin, end) in such a way that all
//    elements for which the predicate p returns true precede all elements for
//    which predicate() returns false. Relative order of the elements is not
//    preserved. */
// template <class ForwardIterator, class T>
// ForwardIterator partition(
//     ForwardIterator begin,
//     ForwardIterator end,
//     bool predicate(const T &))
// {
//     typename ForwardIterator first_false = find_if(begin, end, predicate);
//     for (typename ForwardIterator current = first_false; current != end; ++current)
//         if (predicate(*current))
//             *first_false++ = std::move(*current);
//     return first_false;
// }

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
