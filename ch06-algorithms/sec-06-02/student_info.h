#ifndef GUARD_student_info_h
#define GUARD_student_info_h

// student_info.h
#include <iostream>
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

void do_average_grade_by_homework_status(
    std::ostream &,
    const std::string &,
    double f(const StudentInfo &),
    const std::vector<StudentInfo> &,
    const std::vector<StudentInfo> &);

bool compare_by_name(const StudentInfo &student_x, const StudentInfo &student_y);
std::istream &read(std::istream &stream_in, StudentInfo &student);

bool did_all_hw(const StudentInfo &);

double grade_using_median(const StudentInfo &);
double grade_using_mean(const StudentInfo &);
double grade_using_median_optimistic(const StudentInfo &);

double grade(const StudentInfo &);
double grade(double, double, double);
double grade(double, double, const std::vector<double> &);

bool fgrade(const StudentInfo &);
bool pgrade(const StudentInfo &);

std::vector<StudentInfo> extract_fails(std::vector<StudentInfo> &);

#endif
