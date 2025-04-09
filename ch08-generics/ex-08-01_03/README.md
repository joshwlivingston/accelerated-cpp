# Accelerated C++
## Chapter 8 Exercises 1 and 3

### Exercise 1

>Note that the various `analysis` functions we wrote in §6.2/110 share the same behavior;
they differ only in terms of the functions they call to calculate the final grade. Write a template
function, parameterized by the type of the grading function, and use that function to evaluate
the grading schemes.

### Exercise 3
>As we learned in §4.1.4/58, it can be expensive to return (or pass) a container by value.
>Yet the median function that we wrote in §8.1.1/140 passes the vector by value. Could we
>rewrite the median function to operate on iterators instead of passing the vector
