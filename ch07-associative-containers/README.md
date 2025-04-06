# Accelerated C++
## Chapter 7: Associative Containers

- **Associative containers** arrange elements based on the values of the elements
themselves.

- Associative containers are built for efficient lookups. They use **keys** to 
store lookup information. The keys can be any value type.

- The most common associative data structure, the **associative array**, stores 
key-value pairs.

- The most common associative array in C++ is the `map`, contained in the `<map>`
    header. `map`'s are `pair`'s, which is a data structure that holds two elements.

- A **default argument** allows the programmer to omit the argument if desired:
```cpp
// sec-07-03/word_index.h
word_index build_word_index(
    std::istream &,
    std::vector<std::string> f(const std::string &) = split);

// sec-07-03/main.cc
word_index word_index = build_word_index(cin);
```
<br>

- Associative containers are self-ordering, so algorithms that change the contents
of containers do not function properly, including reordering algorithms. Instead, 
associative containers provide several operations impossible to efficiently 
implement on sequential containers.

### Maps vs Hash Tables
`map`'s are not hash tables, but are similar.

hash tables have a few key disadvantages, addressed by C++ associative containers:
- A hash function must be supplied for all key types in a hash table
- The hash table's performance is dependent on the details of the hash function
- There is no easy way to retireve elements in a useful order 

C++ assicative containers are slightly slower than the very best hash table structures;
however:
- they outperform naive data structures
- their implementation does not require a programmer-supplied hash function
- they are generally more convenient due to automatic ordering.

### Randomness
- The `rand()` function returns an integer in the range `[0, RAND_MAX]`. So, to 
  generate a random number on the interval `[0, n)`, you must treat the integer
  divsion carefully. See `nrand(const int)` in `random.cc`.
- To successfully call `rand()` in a random fashion, you must first call `srand()` 
  to set the seed to a new starting value:
```cpp
srand(time(0)) // #include <ctime>
```
