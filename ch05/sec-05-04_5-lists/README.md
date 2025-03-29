# Accelerated C++
## Lists
### Chapter 5 Sections 4-5

#### Pitfalls of vector
`vector` is optimized for two main purposes:
- Fast access to arbitrary elements
- Appending to the end of a vector

`vector` is *not optimized* for:
- Inserting elements
- Removing elements

For both inserting and removing into a `vector`, all elements must be shifted in order to preserve fast random access.

To optimize insertion and removal, the data structure likely would not support random access through indices.

#### `list`

- `list`'s, included in `<list>`, are optimized for insertion and deletion of arbitrary elements.
- Because `list`'s are a more complicated data structure, they are slower than `vector`'s when only accessing data sequentially.
- `list`'s do not support indexing, but share many other operations with `vector`'s.
