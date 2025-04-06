#ifndef GUARD_extract_h
#define GUARD_extract_h

#include <algorithm>
#include <iterator>
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

std::vector<StudentInfo> extract(
    std::vector<StudentInfo> &,
    bool f(const StudentInfo &));

std::vector<StudentInfo>::const_iterator partition_students(
    std::vector<StudentInfo>::const_iterator begin,
    std::vector<StudentInfo>::const_iterator end,
    bool f(const StudentInfo &));

bool did_all_hw(const StudentInfo &);
bool fgrade(const StudentInfo &);

double grade(const StudentInfo &);
double grade(double, double, double);
double grade(double, double, const std::vector<double> &);

bool fgrade(const StudentInfo &);

bool did_all_hw(const StudentInfo &);

std::istream &read(std::istream &stream_in, StudentInfo &student);

#endif
