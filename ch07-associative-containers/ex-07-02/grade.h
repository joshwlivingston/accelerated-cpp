#ifndef GUARD_grade_h
#define GUARD_grade_h

// grade.h
#include <vector>

// main.cpp
typedef double Grade;
typedef char LetterGrade;

Grade grade(double, double, double);
Grade grade(double, double, const std::vector<double> &);
LetterGrade letter_grade(Grade);

#endif
