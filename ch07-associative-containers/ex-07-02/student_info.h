#ifndef GUARD_student_info_h
#define GUARD_student_info_h

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "grade.h"

// main.cpp

// Student name and grades
struct StudentInfo
{
    std::string name;             // Student's name
    double midterm;               // Studnet's midterm grade
    double final;                 // Student's final exam grade
    std::vector<double> homework; // Student's homework scores
};

typedef std::vector<StudentInfo> Students;
typedef std::map<LetterGrade, Students> StudentsByLetterGrade;
typedef std::map<LetterGrade, int> CountsByLetterGrade;

void get_letter_grades(const Students &, StudentsByLetterGrade &);
void get_letter_grades(const Students &, CountsByLetterGrade &);

LetterGrade letter_grade(const StudentInfo &);
Grade grade(const StudentInfo &);
bool compare_by_name(const StudentInfo &, const StudentInfo &);
std::istream &read(std::istream &, std::ostream &, StudentInfo &);

#endif
