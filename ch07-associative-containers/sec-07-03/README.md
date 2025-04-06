# Accelerated C++
## Chapter 7 Section 3

Our aim is to create a program that generates an index of where words occur in a given input.
To achieve this, we create a map of each word that show the number of occurrences by line.
This functionality is built in `build_word_index()`, in `word_index.cc`.

Our implementation differs slightly from the book, which records the lines as a vector. Using
the map, however, allows for the same information tob be stored, but more efficiently.
