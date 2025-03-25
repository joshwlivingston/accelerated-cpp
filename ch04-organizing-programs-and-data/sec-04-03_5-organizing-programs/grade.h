#ifndef GUARD_grade_h
#define GUARD_grade_h

// grade.h
#include "student_info.h"

#include <vector>

double grade(double, double, double);
double grade(double, double, const std::vector<double> &);
double grade(const StudentInfo &);

#endif
