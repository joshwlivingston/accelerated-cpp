# Accelerated C++
## Chapter 7: Associative Containers

**Associative containers** arrange elements based on the values of the elements
themselves.

Associative containers are built for efficient lookups. They use **keys** to 
store lookup information. The keys can be any value type.

The most common associative data structure, the **associative array**, stores 
key-value pairs. The most common associative array in C++ is the `map`, 
contained in the `<map>` header. `map`'s are `pair`'s, which is a data structure
that holds two elements.

Associative containers are self-ordering, so algorithms that change the contents
of containers do not function properly, including reordering algorithms. Instead, 
associative containers provide several operations impossible to efficiently 
implement on sequential containers.
