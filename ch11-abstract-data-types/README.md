# Accelerated C++
## Chapter 11: Building abstract data types

Our aim in the chapter is to develop a class with basic functionality similar
to that of a `vector`. This will not be a full implementation of `vector`;
rather, one that allows us to implement the class while ignoring the mysterious
but important work of optimizing these classes for the standard library.

Our implementation will be for the class `Vec`, defined in `"vec.h"`.

### Class invariant
The **class invariant** establishes the conditions that validate the class. In
the case of `Vec`, the class invariant is threefold:
1. `data` points to first element, if any, and is zero otherwise
2. `data <= avail <= limit`
3. `[data, avail)` represents the range of *constructed* elements
4. `[data, limit)`  represents the range of *available* elements

To maintain validity, establish the invariant upon the class's construction,
and ensure no public member functions can falsify the invariant.

In the case of `Vec`, that means preventing public member fuctions from
modifying the values of `data`, `avail`, or `limit`, which they do not.

By implementing the validation scheme in private member functions, we prevent
unintended behavior when our class is used. Specifically, it allows for the
user to work with a class in a way that would generally be expected.

The invariant also allows for a guideline when implementing the class. For the
`Vec` to be valid, the invariant must be true. So, any part of the
implementation must preserve the truth of the invariant in order to preserve
validity.

### Memory management
The `<memory>` header provides `allocator<T>`, which allocates a block of
memory of a specified type and returns a pointer to the address of the first
block.

`allocator<T>` provides four member functions and two nonmember functions
suited to the needs of the `Vec` class:
```cpp
template<class T> class allocator {
// ...
public:
    // ...
    // allocates typed but uninitialized storage of specified size
    T* allocate(std::size_t);

    // frees unintialized storage
    void deallocate(T*, std::size_t);

    // construct a single object
    void construct(T* const T&);

    // destroy a single uninitialized object
    void destroy(T*);
    // ...
// ...
};

// initialize uninitialized space with provided value
template<class Out, class T> void uninitialized_fill(Out, Out, const T&);

// initialize uninitialized space, copying from sequence
template<class In, class Out> Out uninitialized_copy(In, In, Out);
```

### Assignment is not initialization!
- **Constructors** always control *initialization*.
- The **`operator=`** member function always controls *assignment*.
```cpp
// initialize v with existing vec
Vec<T> v = vec_1; // uses copy constructor b/c it has const `Vec&` as param

// assign new vec to v
v = vec_2; // invokes `operator=`, which is assignment
```

### Designing a class (gathering requirements)
The first step in designing a class is to design the interface desired out of
that class:
```cpp
Vec<T> ve;                      // construct: empty Vec
Vec<double> v(100)              // construct: populated Vec

Vec<T>::const_iterator b;       // type: const iterator
Vec<T>::size_type i;            // type: size

for (i = 0; i != v.size(); ++i) // member: return length of Vec
    cout << v[i];               // operator: [] for indexing

b = v.begin();                  // member: return iterator @ start
e = v.end();                    // member: return iterator @ end
```
Based on this simple usage of our `Vec`, we already have a number of
requirements:
- constructor: return empty Vec
- constructor: return populated Vec of specified size
- type: const iterator
- type: size
- operator: [] for indexing
- member: return length of Vec
- member: return iterator @ start
- member: return iterator @ end

Then, based on those requirements, we find we also need twqo of the below (the
third can be obtained using any other two):
- the address of the first element (for iteratator @ start)
- the address of one past the last element (for iterator @ end)
- the number of elements (for size())

It's an abitrary decision, but we well choose to store the two addresses, and
to calculate size using those two addresses.

### Rule of three
In class design, if you need a destructor operator, it it highly likely that
you also need both a copy operator and an assignment operator. The same goes
for either of the other two operators. This relationship between the three
operators is known as the **rule of three**.
