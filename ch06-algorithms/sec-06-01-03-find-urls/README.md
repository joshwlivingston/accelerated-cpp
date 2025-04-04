# Accelerated C++
## Chapter 6 Section 1.3

### Using iterators instead of indices
In `url.cc`, we use iterators to identify the URL's in a provided string.

In `main()`, I use `back_inserter()` from `<iterators>` to copy urls results
into the output as they stream in.
