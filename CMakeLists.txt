cmake_minimum_required(VERSION 3.14)
project(accelerated-cpp)

# Chapter 05 Exercise 01
add_executable(
    ex-05-01 
    ch05-sequential-containers/ex-05-01-permuted-index/permuted_index.cc 
    ch05-sequential-containers/ex-05-01-permuted-index/strings.cc 
    ch05-sequential-containers/ex-05-01-permuted-index/stringvec.cc
)

# Chapter 05 Exercises 02-04
add_executable(
    ex-05-02_4 
    ch05-sequential-containers/ex-05-02_4-vector-list/main.cc 
    ch05-sequential-containers/ex-05-02_4-vector-list/student_info.cc 
    ch05-sequential-containers/ex-05-02_4-vector-list/grade.cc 
    ch05-sequential-containers/ex-05-02_4-vector-list/median.cc 
    ch05-sequential-containers/ex-05-02_4-vector-list/read.cc
)

# Chapter 05 Exercise 05
add_executable(
    ex-05-05
    ch05-sequential-containers/ex-05-05/main.cc
    ch05-sequential-containers/ex-05-05/strvec.cc
)

# Chapter 05 Exercise 06
add_executable(
    ex-05-06
    ch05-sequential-containers/ex-05-06/main.cc 
    ch05-sequential-containers/ex-05-06/students.cc 
    ch05-sequential-containers/ex-05-06/student_info.cc 
    ch05-sequential-containers/ex-05-06/grade.cc 
    ch05-sequential-containers/ex-05-06/median.cc 
    ch05-sequential-containers/ex-05-06/read.cc
)

# Chapter 05 Exercise 09
add_executable(
    ex-05-09
    ch05-sequential-containers/ex-05-09-lowercase-sorting.cc
)

# Chapter 05 Exercise 10
add_executable(
    ex-05-10
    ch05-sequential-containers/ex-05-10-palindromes/main.cc
    ch05-sequential-containers/ex-05-10-palindromes/palindromes.cc
)

# Chapter 05 Exercise 11
add_executable(
    ex-05-11
    ch05-sequential-containers/ex-05-11-ascender-descenders/main.cc
    ch05-sequential-containers/ex-05-11-ascender-descenders/ascender_descender.cc
    ch05-sequential-containers/ex-05-11-ascender-descenders/strvec.cc
    ch05-sequential-containers/ex-05-11-ascender-descenders/charvec.cc
)

# Chapter 06 Section 1.1
add_executable(
    sec-06-01-01
    ch06-algorithms/sec-06-01-01-split/main.cc
    ch06-algorithms/sec-06-01-01-split/split.cc
)

# Chapter 06 Section 1.3
add_executable(
    sec-06-01-03
    ch06-algorithms/sec-06-01-03-find-urls/main.cc
    ch06-algorithms/sec-06-01-03-find-urls/url.cc
)

# Chapter 06 Section 02
add_executable(
    sec-06-02
    ch06-algorithms/sec-06-02/main.cc
    ch06-algorithms/sec-06-02/student_info.cc
    ch06-algorithms/sec-06-02/doublevec.cc
)

# Chapter 06 Exercise 01
add_executable(
    ex-06-01
    ch06-algorithms/ex-06-01/main.cc
    ch06-algorithms/ex-06-01/frame.cc
    ch06-algorithms/ex-06-01/strvec.cc
)

# Chapter 06 Exercises 03-04
add_executable(
    ex-06-03_4
    ch06-algorithms/ex-06-03_4-back-inserter/main.cc
)

# Chapter 06 Exercises 07-08
add_executable(
    ex-06-07_8
    ch06-algorithms/ex-06-07_8-stable-partition/main.cc
    ch06-algorithms/ex-06-07_8-stable-partition/student_info.cc
    ch06-algorithms/ex-06-07_8-stable-partition/doublevec.cc
)

# Chapter 06 Exercise 09
add_executable(
    ex-06-09
    ch06-algorithms/ex-06-09/main.cc
    ch06-algorithms/ex-06-09/concat.cc
)

# Chapter 07 Section 02
add_executable(
    sec-07-02
    ch07-associative-containers/sec-07-02-counting/main.cc
)

# Chapter 07 Section 03
add_executable(
    sec-07-03
    ch07-associative-containers/sec-07-03/main.cc
    ch07-associative-containers/sec-07-03/split.cc
    ch07-associative-containers/sec-07-03/word_index.cc
)

# Chapter 07 Section 04
add_executable(
    sec-07-04_05
    ch07-associative-containers/sec-07-04_05-mad-libs/main.cc
    ch07-associative-containers/sec-07-04_05-mad-libs/mad_libs.cc
    ch07-associative-containers/sec-07-04_05-mad-libs/split.cc
    ch07-associative-containers/sec-07-04_05-mad-libs/random.cc
)

# Chapter 07 Exercise 01
add_executable(
    ex-07-01
    ch07-associative-containers/ex-07-01/main.cc
)

# Chapter 07 Exercise 02
add_executable(
    ex-07-02
    ch07-associative-containers/ex-07-02/main.cc
    ch07-associative-containers/ex-07-02/student_info.cc
    ch07-associative-containers/ex-07-02/doublevec.cc
    ch07-associative-containers/ex-07-02/grade.cc
    ch07-associative-containers/ex-07-02/median.cc
)

# Chapter 07 Exercise 06
add_executable(
    ex-07-06
    ch07-associative-containers/ex-07-06-mad-libs-no-recursion/main.cc
    ch07-associative-containers/ex-07-06-mad-libs-no-recursion/mad_libs.cc
    ch07-associative-containers/ex-07-06-mad-libs-no-recursion/split.cc
    ch07-associative-containers/ex-07-06-mad-libs-no-recursion/random.cc
)

# Chapter 07 Exercise 08
add_executable(
    ex-07-08
    ch07-associative-containers/ex-07-08/main.cc
    ch07-associative-containers/ex-07-08/word_index.cc
    ch07-associative-containers/ex-07-08/url.cc
    ch07-associative-containers/ex-07-08/split.cc
)

# Chapter 07 Exercise 09
add_executable(
    ex-07-09
    ch07-associative-containers/ex-07-09/main.cc
    ch07-associative-containers/ex-07-09/random.cc
)

# Chapter 08 Exercises 01 and 03
add_executable(
    ex-08-01_03
    ch08-generics/ex-08-01_03/main.cc
    ch08-generics/ex-08-01_03/student_info.cc
    ch08-generics/ex-08-01_03/doublevec.cc
)

# Chapter 08 Exercise 02
add_executable(
    ex-08-02
    ch08-generics/ex-08-02-algorithm-implementations/main.cc
)

# Chapter 08 Exercise 04
add_executable(
    ex-08-04
    ch08-generics/ex-08-04-swap/main.cc
)

# Chapter 08 Exercise 05
add_executable(
    ex-08-05
    ch08-generics/ex-08-05-mad-libs-iterators/main.cc
    ch08-generics/ex-08-05-mad-libs-iterators/mad_libs.cc
    ch08-generics/ex-08-05-mad-libs-iterators/random.cc
    ch08-generics/ex-08-05-mad-libs-iterators/utils.cc
)

# Chapter 09 Notes
add_executable(
    ch-09
    ch09-classes/main.cc
    ch09-classes/student_info.cc
)

# Chapter 10 Section 1.1
add_executable(
    sec-10-01-01
    ch10-arrays-and-pointers/hello-pointers.cc
)

# Chapter 10 Section 3
add_executable(
    sec-10-03
    ch10-arrays-and-pointers/array-length.cc
)

# Chapter 10 Section 4
add_executable(
    say
    ch10-arrays-and-pointers/args-to-main.cc
)

# Chapter 10 Section 5
add_executable(
    sec-10-05
    ch10-arrays-and-pointers/file-streams.cc
)

# Chapter 10 Exercise 2-3
add_executable(
    ex-10-02_03
    ch10-arrays-and-pointers/ex-10-02_03/main.cc
)
