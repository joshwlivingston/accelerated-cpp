# Accelerated C++

## Chapter 8: Generics

-   A **generic function**, like `std::find()` is defined such that the types used are known until the function is run.
-   In C++, generic functions are implemented through **template functions**.
-   Templates behave similary, except for differences arising as consequences of the type used in the **template paramter**.
-   Template definitions may need to be included, in addition to template headers
    -   Question: Does this mean templates should have their own .h/.cc file pair?

Consider a template function for `median()`:

``` cpp
// template header says we are defining a template function that will take a type parameter
template<class T>

// the implementaiton will bind T to the type determined at compilation
// the code is instantiated with a new T for each invocation
//   i.e., the implementation will compile an instance of the function that replaces T to the type
T median(vector<T> v)
{
    // typename keyword tells implementation that vector<T>::size_type is the name of a type
    // necessary because implementation does not recognize vector<T>::size_type until compile time
    typedef typename vector<T>::size_type vec_sz;
    const vec_sz size = v.size();
    if (size == 0)
        throw domain_error("median of empty vector is not defined");
    
    sort(v.begin(), v.end());

    const vec_sz mid = size / 2;
    return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}
```

<br>

### Container Access Strategies and Iterator Categories

Five **container access strategies** exist in the C++ standard library, each
corresponsing to a distinct **iterator category**.

1. An **input iterator** provides for **read-only sequential access** and supports
   the following operations: - `++` (prefix and postfix), `*` (dereference 
   operator for reading only), `->`, `==`, and `!=`.
2. An **output iterator** provides **sequential write-only access** and supports the 
   following operations: `++` (prefix and postfix), `*` (dereference operator 
   for writing only), and `=`
3. A **forward iterator** provides **sequential read-write access** and supports all 
   *input iterator* and *output iterator* operations.
4. A **bidirectional iterator** provides **forward and backward read-write access**, 
   supporting all *forward iterator* operations and `--`, used for decrementing the
   iterator.
5. A **random-access iterator** provides **random access**, allowing for access to an
   arbitrary element. Random-access rely on arithmetic operations, and support, in
   addition to the *bidirectional iterator* operators, `+`, `-`, `[]` (equivalent 
   to `*(p + n)`), `<`, `>`, `<=`, `>=`

### contianer.end()
`.end()` marks the element one past the end of a container. There are three reasons
for what may seem to be an odd convention:
1. If the container had no elements, there would be no way to mark the end
2. We can use `it != end` in loop conditions to process `[begin, end)`
3. We can use `.end()` to mark out-of-range
