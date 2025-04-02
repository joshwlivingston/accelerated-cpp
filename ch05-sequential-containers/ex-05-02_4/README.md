# Accelerated C++
## Exercises 05.02 - 05.04

Coalescing the instructions of all three exercises, we will implement a program and test the speed file sizes using a swapped `typedef` in `main()`.

I used the code from
[sec-05-04_5-lists](https://github.com/joshwlivingston/accelerated-cpp/tree/main/ch05-sequential-containers/sec-05-04_5-lists)
as a starting place.

### 05.02
Write the complete new version of the student-grading program, which extracts
records for failing students, using `vector`s. Write another that uses `list`s.
Measure the performance difference on input files of ten lines, 1,000 lines, and 10,000 lines.

### 05.03
By using a `typedef`, we can write one version of the program that implements
either a `vector`-based solution or a `list`-based one. Write and test this
version of the program.

### 05.04
Look again at the driver functions you wrote in the previous exercise. Note
that it is possible to write a driver that differs only in the declaration of
the type for the data structure that holds the input file. If your vector and
list test drivers differ in any other way, rewrite them so that they differ
only in this declaration.
