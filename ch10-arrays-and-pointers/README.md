# Accelerated C++
## Chapter 10: Pointers and Arrays

- An **array** is a container, similar to a `vector` but less powerful.
- A **pointer** is a kind of random-access iterator, essential for accessing
  elements of array plus much else.
- Arrays and pointers are virtually inseparable from each other.

### Pointers
- **Pointers** represent the **address** of an object. All distinct objects
  have unique pointers.
- If you know the element, you also know its address. If you know the address,
  you also know the element.
- If `x` is an object, then `&x` is the address of the object. `&` is the
  **address operator**.
- If `p` is an address, then `*p` is the object itself. `*` is the
  **dereference operator**.
- If `p` contains the address of `x`, then `p` is a **pointer** that
  **points to** `x`.
- Conerting 0 to a pointer results in the `null pointer`, and is always a
  unique value to that of any other element.
- The address of an object of type `T` has type `pointer to T` written as `T*`.

Suppose we have `x`, an object of type `int`:
```cpp
int x;
```

We can define `p` with the type `pointer to int`, to allow `p` to contain the
address of `x`:
```cpp
int *p; // *p has type int
```

### Pointers to funcitons
Functions are not first class objects in C++ - all a program can do with a
function is call it or access its address.

When a fucntions is passed to another function, the program will convert the
passed function as a pointer to that function, and pass the pointer instead.

When you receive the pointer to a function, all you can do is call it or
re-access its address.

We can declare a reference to a pointer using `*`, the dereference operator:
```cpp
int (*fp)(int);
```

Here `fp` is a pointer to a function that takes an `int` as an argument and
returns an `int`.

In another case, say, we have a funciton `f`:
```cpp
int f(int n) { return ++n; }
```

Because functions can only be referenced/dereferenced and called, assignment of
a function to another object is treated as an assingment of the pointer to that
function:
```cpp
// these are equivalent statements - both declare fp as the pointer to f
fp = &f;
fp = f;
```

Similarly, calling `f()` through `fp()` can occur multiple ways:
```cpp
// both are equivalent statements:
int i = (*fp)(1);
int i = fp(1);
```

You can define a function's parameters through a `typedef`:
```cpp
typedef int (*incrementer)(int);
```

And similarly use that type as a function parameter or return:
```cpp
incrementer get_incrementer();
```

### Arrays
- **Arrays** are containers of one or more objects of the same element type.
- The name of an array is a *pointer to its first element*.
- An array's *size must be pre-defined* at compile time.
- Arrays are not classes so they *do not have members*.
- The `<cstddef>` header defines `size_t`, which can and should be used for the
  *size of an array*. `size_t` uses an appropriate `unsigned` type.
- `size_type` is for *containers*; `size_t` is for *arrays*.

#### Array lengths
- `sizeof()` returns a `size_t` value reporting the size of the object in bytes
- When used on an array, `sizeof()` returns the size of the *entire array*.

So, to calculate the length of an array, divide the size of the array by the
size of one element:
```cpp
#include <cstddef>

double arr[4];
std::size_t arr_length = sizeof(arr) / sizeof(*arr);
```

### Pointer arithmetic
Recall that *pointers* are **random-access iterators**. So, we can add and
subtract to the iterators.

- If `p` points to the `n`'th element of `v`, then `p + m` points to the
  `n + m`'th element of `v`, assuming valid conditions (see note below).
- `p - q` is defined such that `(p - q) + q == p`, and has the type
  `ptrdiff_t`, defined in `<cstddef>`.

Instead of calling `v.end()`, we can increment the pointer when needed:
```cpp
// initialize an array of doubles with legnth 3
const double::size_t kDim = 3;
double coords[kDim];

// copy array into a std::vector
std::vector<double> v;

// no .begin() and .end() on arrays, so use pointer arithmetic instead
std::copy(coords, coords + kDim, std::back_inserter(v));
```

#### Valid pointer conditions
Let `a` be an `n`-element array. Then the following are true:
- `a + i` is valid *if and only if* `0 <= i <= n`
- `a + i` refers to an element of `a` *if and only if* `0 <= i < n`

### Indexing
- Since pointers are random-access iterators, they support indexing. `p[n]`
  refers to the `n`'th *element* after `p`.
- As noted in chapter 8, `p[n]` is equivalent to `*(p + n)`.
- This, taken with the fact that `v` points to the first element of `v`, means
  that `v[n]` will refer to the `n`'th element of `v`.
- That `[]` indexes arrays is a property of pointers and random-access
  iterators, not arrays themselves directly.

### String literals
- **string literals** are arrays of `const char`
- While `char`'s use `''`, **string literals use `""`**.
- `strlen()` provides the length of an array of characters, up to the null
  pointer
  
When initializing a character array, you can specify that pointers do not
strictly increment by 1:
```cpp
char* const letter_grades[] = {"A+", "A", "A-", "B+", "B", "B-", 
                               "C+", "C", "C-", "D", "F"}
```

Here, `letter_grades` is an array of constant pointers to const char
(`char* const`). Each element points to the initial element of each provided
string literal.
| Call                | Value                                |
| ------------------- | ------------------------------------ |
| `letter_grades `    | [address of first character in "A+"] |
| `*letter_grades`    | `"A+"`                               |
| `letter_grades + 1` | [address of first character in "A"]  |
| `letter_grades[1]`  | `"A"`                                |
| `letter_grades + 2` | [address of first character in "A-"] |
| `letter_grades[2]`  | `"A-"`                               |
| `letter_grades + 3` | [address of first character in "B+"] |
| `letter_grades[3]`  | `"B+"`                               |

### Managing external files
- To read input from a file stream use the type `ifstream`
- The `ofstream` type is used for an output stream to files
- Both types exist in the `<fstream>` header.

### Memory management
Three kinds of memory management exist in C++: **automatic**,
**statically allocated**, and **dynamically allocated**

*Note, smart pointers were introduced in C++11, and are now the de-facto mode
of memory management. They "smartly" deallocate memory when pointers are out of
scope. More to learn in a next book!

#### Automatic memory management
**Automatic** memory management is associated with local variables. When a
local variable is no longer in scope, the memory it occupies is *automatically*
deallocated.

For example, you cannot return a pointer to a local variable:
```cpp
// do not run!
int* pointer_to_local() {
    int x;
    return &x; // if you do this, the unexpected will occur
}
```

#### Statically allocated memory
One way to return a pointer to a variable is to return a pointer to a *static*
variable. Such allocation is known is **statically allocated** memory:
```cpp
int* pointer_to_static() {
    static int x;
    retunr &x; // valid
}
```
Each time `pointer_to_static()` is called, a pointer to the static object x
will be returned. The `static` keyword says that we are only to allocate this
memory once.

#### Dynamically allocated memory
If you want to return a pointer to a *new* object, one you wish to *delete*
later, you use **dynamic allocation**.
```cpp
// define a pointer to an integer object, with a value of 42
int* p = new int(42);

// increment the object to which p points by 1
++*p;

// deallocate the memory utilied by the object to which p refers
delete p;
```

So, we can return a pointer to a dynamically allocated object:
```cpp
int* pointer_to_dynamic() {
    return new int(0);
}
```

The functionality is similar for arrays:
```cpp
int* p = new int[10];
++*p; // increments first value only
delete[] p; // deallocates space occupied by entire array
```
