#ifndef GUARD_student_info_h
#define GUARD_student_info_h

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "median.h"

// Student name and grades
struct StudentInfo
{
    std::string name;             // Student's name
    double midterm;               // Studnet's midterm grade
    double final;                 // Student's final exam grade
    std::vector<double> homework; // Student's homework scores
};

bool compare_by_name(const StudentInfo &student_x, const StudentInfo &student_y);
std::istream &read(std::istream &stream_in, StudentInfo &student);

double grade(StudentInfo &);
double grade(double, double, double);
double grade(double, double, std::vector<double> &);

bool fgrade(StudentInfo &);
bool pgrade(StudentInfo &);

bool did_all_hw(const StudentInfo &);

std::vector<StudentInfo> extract_fails(std::vector<StudentInfo> &);

template <class grade_num>
void compare_average_grades(
    std::ostream &out,
    const std::string &name,
    grade_num analyze(StudentInfo &),
    std::vector<StudentInfo> &students_x,
    std::vector<StudentInfo> &students_y)
{
    // transform() is a copy that uses the result of the provided function
    typename std::vector<grade_num> grades_x;
    transform(students_x.begin(), students_x.end(), std::back_inserter(grades_x), analyze);

    typename std::vector<grade_num> grades_y;
    transform(students_y.begin(), students_y.end(), std::back_inserter(grades_y), analyze);

    out << name << ":" << std::endl

        << "avg of group 1: "
        << median<double>(grades_x.begin(), grades_x.end()) << std::endl

        << "avg of group 2: "
        << median<double>(grades_y.begin(), grades_y.end()) << std::endl;
}

double grade_using_median(StudentInfo &);
double grade_using_mean(StudentInfo &);
double grade_using_median_optimistic(StudentInfo &);

#endif
