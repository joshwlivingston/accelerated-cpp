# Accelerated C++
## Chapter 10 Exercises 2-3

### Exercise 2
>Rewrite the median function from §8.1.1/140 so that we can call it with either
>a vector or a built-in array. The function should allow containers of any
>arithmetic type.

### Exercise 3
>Write a test program to verify that the median function operates correctly.
>Ensure that calling median does not change the order of the elements in the
>container.

### Answer
Based on pointer arithmetic, the new `median()` template function has been
implemented in `"median.h"`.
