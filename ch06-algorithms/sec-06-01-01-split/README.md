# Accelerated C++
## Chapter 6 Section 1.1

### Using iterators instead of indices
In `split.cc`, we rework the `split()` function to work off of iterators over
the strings, as opposed to indices on the strings.

One thing to note are `is_space()` and `is_not_space()` in `char.cc`. These 
functions are required so that the compiler knows which overloaded `isspace()`
to use inside `find_if()`.
