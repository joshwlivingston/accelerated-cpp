# Accelerated C++
## Chapter 6: Using Library Algorithms

Unless otherwise noted, all algorithms introduced come from the `<algorithm>`
header.

### Using iterators instead of indices
Consdier the act of copying the contents of one vector, `vec_to_copy`, into
another vector, `vec_to_return`.
```cpp
vec_to_return.insert(vec_to_return.end(), vec_to_copy.begin(), vec_to_copy.end());
```

The functionality here can be achieved even more generally, by separating the
copying from the insertion:
```cpp
copy(vec_to_copy.begin(), vec_to_copy.end(), back_inserter(vec_to_return));
```

The above is comprised of `copy()`, a generic algorithm, and `back_inserter()`,
an iterator adaptor.

Separating the aglorithm from the iteration allows the programmer to choose which
specfic operations to use.

### Generic Algorithm
A **generic algorithm** does not belong to any particular container, but instead
modifies its behavior based on the data passed to it. Usually, the standard 
library algorithms take iterators for arguments.

The `copy` algorithm takes three iterators as arguments:
```cpp
copy(begin, end, out);
```

is equivalent to:
```cpp
while (begin != end)
    *out++ = *begin++;
```

### Iterator Adaptor
**Iterator adaptors**, defined in `<iterator>`, are functions that yield iterators
with certain properties. The most common iterator adaptor is `back_inserter()`, which
appends values to its argument when the iterator it yields is used as a destination.

### Postfix operators
Operators can be applied after variables as well, with different bahaviors.
These operators are known as **postfix** operators, as opposed to **prefix**
operators.

For example:
```cpp
it = begin++;
```

is equivalent to 

```cpp
it = begin;
++begin;
```

### Algorithms
Algorithms work on the elements of containers, not the containers themselves.

For example, in the following:
```cpp
remove_if(students.begin(), students.end(), fgrade);
```

No elements are actually removed from students. Instead, elements that are not "removed"
are placed at the beginning of students. To actually remove, a second call, to `erase()`,
is necessary:
```cpp
students.erase(remove_if(students.begin(), students.end(), fgrade), students.end())
```

Note that in the above, `remove_if()` returns an iterator correesponding to the location of 
the first element of elements matching the provided predicate.

Most algorithms return iterators, and return the ending iterator on "no match."

So the code for a general "search" algorithm is:
```
has_match = search(iter_begin, iter_end, predicate) != iter_end;
```
