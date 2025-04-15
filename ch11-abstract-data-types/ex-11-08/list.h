#ifndef GUARD_List_h
#define GUARD_List_h

/*
Implements a simplified version of std::list

Types:
- iterator
- const_iterator
- size_type
- value_type

Constructors/Assignment:
- empty
- copy
- assignment
- size, value

Destructors:
- destructor

Operators:
- assignment

Functions:
- begin()
- end()
- size()
- erase()
- clear()

*/

#include <cstddef>
#include <memory>

#include "iterator_bidirectional.h"

/* List, implemented as doubly-linked list */
template <class T>
class List
{
public:
    typedef IteratorBidirectional<T> iterator;
    typedef const IteratorBidirectional<T> const_iterator;
    typedef std::size_t size_type;
    typedef T value_type;

    List()
    {
        set_pointers_to_zero();
    }

    List(const List &input)
    {
        create(*input);
    }

    explicit List(size_type &n, const T &val)
    {
        create(n, val);
    }

    // List &operator=(const List &);

    // ~List() { uncreate(); }

    iterator begin() { return data; }
    iterator end() { return last; }
    size_type size() { return size_; }

    void erase(iterator &where)
    {
        iterator one_after_where = (*where)++;
        erase(*where, one_after_where);
    }

    void erase(iterator &begin, iterator &end)
    {
        // point `next_` in element before range to one after erased range
        --begin;
        begin.next_ = *end;

        // point `prev_` in one after erased range to element before range
        end->prev_ = *(begin);
        ++begin; // back on input `begin`

        // point `next_` in last erased element to first available element
        --end;
        end.next_ = *start;

        // point class start to start of this erased range
        start = *begin;
    }
    // void resize() { deallocate_unlinked_elements(); }
    // void clear() { uncreate(); }

private:
    void create(const List &);
    void create(const size_type &, const T &);
    // void uncreate();
    // void invalid_uncreate(iterator, iterator);
    void set_pointers_to_zero();
    void swap_with_end(iterator);
    // void deallocate_unlinked_elements();

    /*
    Class invariant:
    1. `start` points to the first allocated block in the array, or 0 if no
       memory has been allocated
    2. `data` points to the first assigned element in the array, or 0 if are no
       elements are assigned
    3. `last` points to one past the last assignned element
    4. `avail` points to one past the last created element
    5. `start` <= `data` <= `last` <= `avail`
    6. [data, last) is the range of all assignened elements
    7. [data, avail) is the range of all allocated elements
    8. [last, avail) is the range of allocated but un-assigned elements
    */
    iterator *start; 
    iterator data;
    iterator last;
    iterator avail;
    size_type size_;

    std::allocator<T> alloc;
};

// template <class T>
// List<T> &List<T>::operator=(const List &rhs)
// {
//     if (this != rhs) // comparing reference to reference
//     {
//         const iterator new_data = alloc.allocate(rhs.size());
//         const iterator new_last = std::uninitialized_copy(rhs.begin(), rhs.end(),
//                                                  new_data);
//         invalid_uncreate(data, avail);
//         data = new_data;
//         last = avail = new_last;
//     }
// }

// template <class T>
// void List<T>::uncreate()
// {
//     invalid_uncreate(data, avail);
//     set_pointers_to_zero();
// }

// template <class T>
// void List<T>::invalid_uncreate(iterator begin, iterator end)
// {
//     iterator current = end;
//     size_type n_destroyed = 0;
//     while (current != begin)
//     {
//         alloc.destroy(--current);
//         ++n_destroyed;
//     }
//     alloc.deallocate(begin, n_destroyed);
// }

template <class T>
void List<T>::set_pointers_to_zero()
{
    start = data = last = avail = 0;
}

template <class T>
void List<T>::create(const List &input)
{
    data = alloc.allocate(input.size());
    // last = avail = std::uninitialized_copy(input.begin(), input.end(), data);
}

template <class T>
void List<T>::create(const size_type &n, const T &val)
{
    data = *alloc.allocate(n);
    // last = avail = std::uninitialized_fill_n(data, n, val);
}

#endif
