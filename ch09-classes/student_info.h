#ifndef GURAD_student_h
#define GUARD_student_h

#include <iterator>
#include <istream>
#include <stdexcept>
#include <string>
#include <vector>

#include "algorithms.h"

class Student
{
public:
    typedef double grade_num;
    typedef std::vector<grade_num> grade_nums;
    typedef std::back_insert_iterator<grade_nums> grade_nums_inserter;

    Student();
    Student(std::istream &);

    std::istream &read(std::istream &);
    double grade() const;

    /* Accessor function for the student's name */
    std::string name() const { return name_; }

    /* Checks if student data is valid */
    bool valid() const { return !homework.empty(); }

private:
    std::string name_;
    grade_num midterm;   // The student's midterm exam grade
    grade_num final;     // The student's final exam grade
    grade_nums homework; // The student's homework grades
};

double grade(
    const Student::grade_num,
    const Student::grade_num,
    Student::grade_nums::const_iterator,
    Student::grade_nums::const_iterator);

double grade(
    const Student::grade_num,
    const Student::grade_num,
    const Student::grade_num);

bool compare_name(const Student &, const Student &);

#endif
