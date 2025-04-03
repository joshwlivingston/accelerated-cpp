cmake_minimum_required(VERSION 3.14)
project(accelerated-cpp)

# Chapter 05 Exercise 01
add_executable(
    ex-05-01 
    ch05-sequential-containers/ex-05-01/permuted_index.cc 
    ch05-sequential-containers/ex-05-01/strings.cc 
    ch05-sequential-containers/ex-05-01/stringvec.cc
)

# Chapter 05 Exercises 02-04
add_executable(
    ex-05-02_4 
    ch05-sequential-containers/ex-05-02_4/main.cc 
    ch05-sequential-containers/ex-05-02_4/student_info.cc 
    ch05-sequential-containers/ex-05-02_4/grade.cc 
    ch05-sequential-containers/ex-05-02_4/median.cc 
    ch05-sequential-containers/ex-05-02_4/read.cc
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
    ch05-sequential-containers/ex-05-09.cc
)

# Chapter 05 Exercise 10
add_executable(
    ex-05-10
    ch05-sequential-containers/ex-05-10/main.cc
    ch05-sequential-containers/ex-05-10/palindromes.cc
)
