#ifndef GUARD_bidirectional_iterator_h
#define GUARD_bidirectional_iterator_h

#include "iterator_forward.h"

template <class T>
class IteratorBidirectional : protected IteratorForward<T>
{
public:
    using IteratorForward<T>::operator++;

    IteratorBidirectional()
    {
        set_pointers_to_zero();
    }

    IteratorBidirectional(IteratorBidirectional &input)
    {
        assign(input);
    }

    IteratorBidirectional(T &here, IteratorBidirectional &next)
    {
        assign(here, next);
    }

    IteratorBidirectional(IteratorBidirectional &prev, T &here)
    {
        assign(prev, here);
    }

    IteratorBidirectional(IteratorBidirectional &prev, T &here, 
                          IteratorBidirectional &next)

    {
        assign(here, next, prev);
    }

    ~IteratorBidirectional()
    {
        set_pointers_to_zero();
    }

    bool operator==(const IteratorBidirectional &rhs) const
    {
        return Iterator<T>::is_equal(rhs);
    }

    bool operator!=(const IteratorBidirectional &rhs) const
    {
        return !Iterator<T>::is_equal(rhs);
    }

    IteratorBidirectional &operator--() const
    {
        return *prev_;
    }

    using IteratorForward<T>::operator*;

protected:
    void set_pointers_to_zero()
    {
        Iterator<T>::set_pointers_to_zero();
        prev_ = 0;
    }

    void assign(IteratorBidirectional &input)
    {
        assign(*input.data, *input.next_, *input.prev_);
    }

    void assign(T &here, IteratorBidirectional &next)
    {
        this->data = &here;
        this->next_ = &next;
    }

    void assign(IteratorBidirectional &prev, T &here)
    {
        this->data = &here;
        prev_ = &prev;
    }

    void assign(T &new_data, Iterator<T> &new_next, 
                IteratorBidirectional &new_prev)
    {
        this->data = &new_data;
        this->next_ = &new_next;
        prev_ = &new_prev;
    }

    IteratorBidirectional *prev_ = 0;
};

#endif // GUARD_bidirectional_iterator_h
