#ifndef GUARD_vec_h
#define GUARD_vec_h

#include <algorithm>
#include <cstddef>
#include <memory>

template <class T>
class Vec
{
public:
    typedef T *iterator;
    typedef const T *const_iterator;
    typedef std::size_t size_type;
    typedef T value_type;

    /*
    The compiler sill synthesize a default copy constructor, assignment
    operator, and destructor for each that is undefined at compile time.
    */

    /*
    The template parameter does not need to be explicit when inside the scope
    of the template.
    */

    // copy constructor
    Vec(const Vec &v) { create(v.begin(), v.end()); }

    Vec &operator=(const Vec &);

    // empty constructor
    Vec() { create(); }

    // explicit constructor, (as in 'not implicit')
    // args *must* be present for this constructor to be used.
    // e.g., cannot do `Vec v = 100;` to call this constructor
    explicit Vec(size_type n, const T &val = T()) { create(n, val); }

    // destructor
    ~Vec() { uncreate(); }

    // overloading index operator to return reference from data array
    T &operator[](size_type i) { return data[i]; }

    // overloading these two [] operators is allowed because they differ by
    // implict `const` parameter. const parameter says "this member function
    // will not change the class"
    const T &operator[](size_type i) const { return data[i]; }

    // return array pointers as our iterators
    iterator begin() { return data; }
    const_iterator begin() const { return data; }
    iterator end() { return avail; }
    const_iterator end() const { return avail; }

    // ptrdiff_t (limit - data) converted to size_type on return
    size_type size() const { return limit - data; }

    // append a new element to Vec
    void push_back(const T &val)
    {
        if (avail == limit)
            grow();
        unchecked_append(val);
    }

private:
    iterator data;  // Points to first element, if any, and is zero otherwise
    iterator avail; // Points to one past the last constructed element
    iterator limit; // Points to last available element

    /*
    class invariant:
    1. `data` points to first element, if any, and is zero otherwise
    2. `data` <= `avail` <= `limit`
    3. [`data`, `avail`) represents the range of *constructed* elements
    4. [`data`, `limit`) represents the range of *available* elements

    To validate the invariant, establish the class invariant upon construction.

    Assure public member functions cannot falsify the class invariant. In this
    case, that means preventing the public member functions from modifying the
    values of `data`, `avail`, or `limit`.
    */

    std::allocator<T> alloc; // Handles memory allocation for Vec

    void create();
    void create(const size_type, const T &);
    void create(const_iterator, const_iterator);

    void uncreate();

    void grow();
    void unchecked_append(const T &);
};

// Assignment Operator
// For consistency with built-in assignment operator, it is best to return
// a reference to the lhs of the `=`.
//
// Destroys any data currently in Vec, then creates new data for Vec using rhs.
template <class T>
Vec<T> &Vec<T>::operator=(
    // outside the scope of the template, the template parameter needs to be
    // explicitly declared in the return type

    // inside the scope of a template again, the <T> parameter is optional
    // Vec<T> lhs = rhs;
    const Vec &rhs)
{
    // `this` refers to the new class being created
    // in other words: `this` is `lhs` in the line `Vec<T> lhs = rhs;`
    if (&rhs != this) // necessary logic
    // without the logic (in some form), we would deallocate the rhs,
    // and then have nothing left to create() `this`
    {
        uncreate();
        create(rhs.begin(), rhs.end());
    }

    // we dereference `this` in the return, so that the return type correctly
    // returns the reference to the element to which `this` points
    return *this;
}

// Creates an empty Vec, initializing data with the correct type.
// Used for empty constructor.
template <class T>
void Vec<T>::create() { data = avail = limit = 0; }

// Allocates memory of type T and size n, and assign val to each element.
// Used for explicitly-provided arguments.
template <class T>
void Vec<T>::create(const size_type n, const T &val)
{
    data = alloc.allocate(n);
    limit = avail = data + n;
    std::uninitialized_fill(data, limit, val);
}

// Allocates memory according to input size, and assigns each copied element.
// Used for copy constructor and `operator=`.
template <class T>
void Vec<T>::create(const_iterator begin, const_iterator end)
{
    data = alloc.allocate(end - begin);
    limit = avail = std::uninitialized_copy(begin, end, data);
}

// Runs destructors on all elements in Vec.
// Used to destroy elements in array and free memory.
template <class T>
void Vec<T>::uncreate()
{
    if (data)
    {
        // begin at .end(), one past the last available element
        iterator current = avail;

        // destroy all objects, iterating backwards (does not free memory)
        while (current != data)
            alloc.destroy(--current);

        // free memory of now destroyed objects
        alloc.deallocate(data, size());

        // reset pointers
        data = limit = avail = 0;
    }
}

/*
1. Allocate twice as much space as is currently in use (or 1 block if no
   space is allocated).
2. Copy all elements into new space.
3. Reset pointers to new space. */
template <class T>
void Vec<T>::grow()
{
    // return twice as much space as is currently in use
    const size_type new_size = std::max(2 * size(), size_type(1));

    // allocate new space and copy existing elements into new space
    const iterator new_data = alloc.allocate(new_size);
    const iterator new_avail = std::uninitialized_copy(data, avail, new_data);

    // return old space
    uncreate();

    // reset pointers to newly allocated space
    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

// Construct an object in next available space
// Assumes allocated but initialized space exists at position after `avail`
template <class T>
void Vec<T>::unchecked_append(const T &val)
{
    alloc.construct(avail++, val);
}

#endif // GUARD_vec_h
