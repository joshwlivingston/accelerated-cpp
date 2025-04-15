#ifndef GUARD_iterator_input_h
#define GUARD_iterator_input_h

#include "iterator.h"

/*
Input Iterator, providing read-only sequential access to an array

Needs:

constructor(InputIterator)
constructor(T*)
operator: =(InputIterator)
operator: =(const T &)
s
operator: ++
operator: ==(InputIterator)
operator: !=(InputIterator)
operator: *(read only)
operator: ->
*/

template <class T>
class IteratorInput : protected Iterator<T>
{
public:
    using Iterator<T>::Iterator;
    using Iterator<T>::operator++;

    IteratorInput(T &val, IteratorInput &next) {
        Iterator<T>::assign(val, next); 
    }

    bool operator==(const IteratorInput &rhs) const {
        return Iterator<T>::is_equal(rhs); 
    }

    bool operator!=(const IteratorInput &rhs) const {
        return !Iterator<T>::is_equal(rhs);
    }
};

#endif // GUARD_iterator_input_h
