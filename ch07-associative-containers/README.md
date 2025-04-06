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
