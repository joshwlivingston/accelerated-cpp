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

# Chapter 06 Section 2
add_executable(
    sec-06-02
    ch06-algorithms/sec-06-02/main.cc
    ch06-algorithms/sec-06-02/student_info.cc
    ch06-algorithms/sec-06-02/doublevec.cc
)
