#ifndef GUARD_student_info_h
#define GUARD_student_info_h

// student_info.h
#include <iostream>
#include <string>
#include <vector>

// main.cpp

// Student name and grades
struct StudentInfo
{
    std::string name;             // Student's name
    double midterm;               // Studnet's midterm grade
    double final;                 // Student's final exam grade
    std::vector<double> homework; // Student's homework scores
};

char letter_grade(const StudentInfo &);
double grade(const StudentInfo &);
bool compare_by_name(const StudentInfo &student_x, const StudentInfo &student_y);
std::istream &read(std::istream &stream_in, std::ostream &stream_out, StudentInfo &student);

#endif
