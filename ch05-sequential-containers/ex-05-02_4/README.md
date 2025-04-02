# Accelerated C++
## Exercises 05.02 - 05.04

Coalescing the instructions of all three exercises, we will implement a program and test the speed file sizes using a swapped `typedef` in `main()`.

I used the code from
[sec-05-04_5-lists](https://github.com/joshwlivingston/accelerated-cpp/tree/main/ch05-sequential-containers/sec-05-04_5-lists)
as a starting place.

## Results
Notable differences in speed were not observed until ~4800 students were included in the test data. At that point, using a reaalistic distribution of pass/fails, a notable difference was again not observed: ~0.45 seconds using both a vector and a list.

However, when the fail threshold was increased to 95 and below, substantial differences were observed. The vector processed the students over 1.18 seconds, while the list processed the students in only 0.42 seconds.

So, the data type must be chosen based not only on optimization of specific operators; the frequency of the operation must also be taken into account.

## Exercise Text

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
