# Accelerated C++
## Chapter 6 Exercises 3-4

### Exercise 3

>What does this program fragment do?
```cpp
vector<int> u(10, 100);
vector<int> v;
copy(u.begin(), u.end(), v.begin());
```

This code will write u, but will not copy into `v`, since `copy()` expects its 
third argument to be an output iterator. `v.begin()` returns a `const_iterator`.

In addition, the code will lose the elements of `u`, due to the bad argument in `copy()`.

### Exercise 4
>Correct the program you wrote in the previous exercise to copy from u into v. There are
>at least two possible ways to correct the program. Implement both, and describe the relative
>advantages and disadvantages of each approach.

Two approches here are to use `v.insert()` or `copy(..., back_inserter(v))`. While the former
is more succicnt, the latter separates the copying from the iteration for the programmer.

I opted for `copy()`, to be explicit with my intention.
