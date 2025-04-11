#ifndef GUARD_algorithms_h
#define GUARD_algorithms_h

#include <utility>

namespace algo {

/* Checks whether [begin, end) and a range starting from comparison are
   equal */
template <class InputIteratorIn, class InputIteratorCmp>
bool equal(InputIteratorIn begin, InputIteratorIn end, InputIteratorCmp comp) {
    while (begin != end)
        if (*begin++ != *comp++)
            return false;
    return true;
}

/* Searches for the first occurrence of the sequence of elements
   [matches_begin, matches_end) in the range [begin, end) */
template <class InputIteratorIn, class InputIteratorMatches>
InputIteratorIn search(InputIteratorIn begin, InputIteratorIn end,
                       InputIteratorMatches matches_begin,
                       InputIteratorMatches matches_end) {
    for (; begin != end; ++begin) {
        InputIteratorMatches match_current = matches_begin;
        while (match_current != matches_end)
            if (*begin == *match_current++)
                return begin;
    }
    return begin;
}

/* Returns an iterator to the first element in the range [begin, end) that is
   equal to match (or last if there is no such iterator) */
template <class InputIteratorIn, class TypeInput>
InputIteratorIn find(InputIteratorIn begin, InputIteratorIn end,
                     const TypeInput &match) {
    while (begin != end && *begin != match)
        ++begin;
    return begin;
}

/* Returns an iterator to the first element in the range [begin, end) for which
   predicate() is true (or last if there is no such iterator) */
template <class InputIteratorIn, class TypeInput>
InputIteratorIn find_if(InputIteratorIn begin, InputIteratorIn end,
                        bool predicate(const TypeInput &)) {
    while (begin != end && !predicate(*begin))
        ++begin;
    return begin;
}

/* Copies the elements in the range, defined by [begin, end), to another range
   beginning at destination_begin (copy destination range). */
template <class InputIteratorIn, class OutputIteratorOut>
OutputIteratorOut copy(InputIteratorIn begin, InputIteratorIn end,
                       OutputIteratorOut destination_begin) {
    while (begin != end)
        *destination_begin++ = *begin++;
    return destination_begin;
}

/* Copies the elements in the range, defined by [begin, end), to another range
   beginning at destination_begin (copy destination range), omitting elements
   equal to match. */
template <class InputIteratorIn, class OutputIteratorOut, class TypeInput>
OutputIteratorOut remove_copy(InputIteratorIn begin, InputIteratorIn end,
                              OutputIteratorOut destination_begin,
                              const TypeInput &match) {
    for (; begin != end; ++begin)
        if (*begin != match)
            *destination_begin++ = *begin;
    return destination_begin;
}

/* Copies the elements in the range, defined by [begin, end), to another range
   beginning at destination_begin (copy destination range), omitting elements
   for which predicate() is true. */
template <class InputIteratorIn, class OutputIteratorOut, class TypeInput>
OutputIteratorOut remove_copy_if(InputIteratorIn begin, InputIteratorIn end,
                                 OutputIteratorOut destination_begin,
                                 bool predicate(const TypeInput &)) {
    for (; begin != end; ++begin)
        if (!predicate(*begin))
            *destination_begin++ = *begin;
    return destination_begin;
}

/* Removes all elements that equal match from the range [begin, end) and
   returns a past-the-end iterator for the new end of the range. */
template <class ForwardIteratorIn, class TypeInput>
ForwardIteratorIn remove(ForwardIteratorIn begin, ForwardIteratorIn end,
                         const TypeInput &match) {
    ForwardIteratorIn first_removed = algo::find(begin, end, match);
    for (begin = first_removed; begin != end; ++begin)
        if (*begin != match)
            *first_removed++ = std::move(*begin);
    return first_removed;
}

/* Applies the given function to the the range [begin, end), and stores the
   result in an output range starting from begin_destination */
template <class InputIteratorIn, class OutputIteratorOut, class TypeInput, 
          class TypeOutput>
OutputIteratorOut transform(InputIteratorIn begin, InputIteratorIn end,
                            OutputIteratorOut begin_destination,
                            TypeOutput transform_function(const TypeInput &)) {
    while (begin != end)
        *begin_destination++ = transform_function(*begin++);
    return begin_destination;
}

/* Reorders the elements in the range [begin, end) in such a way that all
   elements for which the predicate p returns true precede all elements for
   which predicate() returns false. Relative order of the elements is not
   preserved. */
template <class ForwardIteratorIn, class TypeInput>
ForwardIteratorIn partition(ForwardIteratorIn begin, ForwardIteratorIn end,
                            bool predicate(const TypeInput &)) {
    ForwardIteratorIn true_partition_end =
        algo::find_if(begin, end, predicate);
    for (begin = true_partition_end; begin != end; ++begin)
        if (predicate(*begin))
            std::swap(*true_partition_end++, *begin);
    return true_partition_end;
}

/* Computes the sum of the given value init and the elements in the range
   [begin, end). */
template <class InputIterator, class T>
T accumulate(InputIterator begin, InputIterator end, T init) {
    while (begin != end)
        init += *begin++;
    return init;
}

/* Computes the mean of the elements in the range [begin, end). */
template <class InputIterator, class T>
T mean(InputIterator begin, InputIterator end) {
    return accumulate<InputIterator, T>(begin, end, 0) / (end - begin);
}

} // namespace algo

#endif
