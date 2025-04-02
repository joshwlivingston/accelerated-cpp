cmake_minimum_required(VERSION 3.14)
project(accelerated-cpp)

# Chapter 05 Exercise 01
add_executable(
    ex-05-01 
    ch05-sequential-containers/ex-05-01/permuted_index.cc 
    ch05-sequential-containers/ex-05-01/strings.cc 
    ch05-sequential-containers/ex-05-01/stringvec.cc
)

# Chapter 05 Exercise 02
add_executable(
    ex-05-02 
    ch05-sequential-containers/ex-05-02_4/main.cc 
    ch05-sequential-containers/ex-05-02_4/student_info.cc 
    ch05-sequential-containers/ex-05-02_4/grade.cc 
    ch05-sequential-containers/ex-05-02_4/median.cc 
    ch05-sequential-containers/ex-05-02_4/read.cc
)
