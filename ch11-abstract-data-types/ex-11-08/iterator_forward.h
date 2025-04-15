#ifndef GUARD_forward_iterator_h
#define GUARD_forward_iterator_h

#include "iterator_input.h"

template <class T>
class IteratorForward : protected IteratorInput<T>
{
public:
    using IteratorInput<T>::IteratorInput;
    using IteratorInput<T>::operator++;

    IteratorForward(T &val, IteratorForward &next)
    {
        IteratorInput<T>::assign(val, next);
    }

    bool operator==(const IteratorForward &rhs) const
    {
        return IteratorInput<T>::is_equal(rhs);
    }

    bool operator!=(const IteratorForward &rhs) const
    {
        return !IteratorInput<T>::is_equal(rhs);
    }

    T &operator*()
    {
        return IteratorInput<T>::dereference();
    }
};

#endif // GUARD_forward_iterator_h
