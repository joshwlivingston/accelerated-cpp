#ifndef GUARD_student_info
#define GUARD_student_info

// student_info.h
#include <iostream>
#include <list>
#include <string>
#include <vector>

// Student name and grades
struct StudentInfo
{
    std::string name;             // Student's name
    double midterm;               // Studnet's midterm grade
    double final;                 // Student's final exam grade
    std::vector<double> homework; // Student's homework scores
};

typedef std::list<StudentInfo> Students;

std::istream &read(std::istream &stream_in, StudentInfo &student_info);
double grade(const StudentInfo &);
double fgrade(const StudentInfo &);
Students extract_fails(Students &);

#endif
