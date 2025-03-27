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
    double final_grade;           // Studnet's final class grade
};
bool compare_by_name(const StudentInfo &student_x, const StudentInfo &student_y);
std::istream &read(std::istream &stream_in, std::ostream &stream_out, StudentInfo &student);

#endif
