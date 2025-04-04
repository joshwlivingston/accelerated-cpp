#include "student_info.h"

#include <algorithm>
#include <numeric>
#include <ios>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>

#include "doublevec.h"

using std::back_inserter;
using std::domain_error;
using std::endl;
using std::find;
using std::istream;
using std::ostream;
using std::remove_copy;
using std::remove_copy_if;
using std::remove_if;
using std::stable_partition;
using std::string;
using std::transform;
using std::vector;

// Return students' homework scores by their having done all homeworks.
void do_average_grade_by_homework_status(
    // The output stream
    ostream &out,

    // The name of the analysis
    const string &name,

    // The grading procedure to be used
    double analysis(const StudentInfo &),

    // A vector of all students who did all homeworks
    const vector<StudentInfo> &students_who_did_all_homework,

    // A vector of students who did not do all homeworks
    const vector<StudentInfo> &students_who_did_not_do_all_homework)
{
    // transform() is a copy that uses the result of the provided function
    vector<double> grades_of_all_hw_students;
    transform(
        students_who_did_all_homework.begin(),
        students_who_did_all_homework.end(),
        back_inserter(grades_of_all_hw_students),
        analysis);

    vector<double> grades_of_some_hw_students;
    transform(
        students_who_did_not_do_all_homework.begin(),
        students_who_did_not_do_all_homework.end(),
        back_inserter(grades_of_some_hw_students),
        analysis);

    out << name << ":" << endl

        << "avg of those who did all homework: "
        << median(grades_of_all_hw_students) << endl

        << "avg of those who did not do all homework: "
        << median(grades_of_some_hw_students) << endl;
}

// Checks if a student did all homeworks
bool did_all_hw(const StudentInfo &student)
{
    // find() will return an iterator corresponding to the position of the matching element
    return find(student.homework.begin(), student.homework.end(), 0) == student.homework.end();
}

// Computes a student's final grade using median() for the hw grade calculation
double grade_using_median(const StudentInfo &student)
{
    try
    {
        return grade(student);
    }
    catch (domain_error)
    {
        return (grade(student.midterm, student.final, 0));
    }
}

// Computes a student's final grade using mean() for the hw grade calculation
double grade_using_mean(const StudentInfo &student)
{
    try
    {
        return grade(student.midterm, student.final, mean(student.homework));
    }
    catch (domain_error)
    {
        return (grade(student.midterm, student.final, 0));
    }
}

// Computes a student's final grade using median() of submitted homeworks for the hw grade calculation
double grade_using_median_optimistic(const StudentInfo &student)
{
    // remove_copy is a misnomer for copy_if_not
    vector<double> grades_of_completed_homeworks;
    remove_copy(student.homework.begin(), student.homework.end(), back_inserter(grades_of_completed_homeworks), 0);

    if (grades_of_completed_homeworks.empty())
    {
        return grade(student.midterm, student.final, 0);
    }

    return grade(student.midterm, student.final, median(grades_of_completed_homeworks));
}

// Return a vector of students that failed, removing those students from the input vector
vector<StudentInfo> extract_fails(vector<StudentInfo> &students)
{
    // remove_copy_if is a misnomer for copy_if_not
    // vector<StudentInfo> failing_students;
    // remove_copy_if(students.begin(), students.end(), back_inserter(failing_students), pgrade);
    // students.erase(remove_if(students.begin(), students.end(), fgrade), students.end());

    vector<StudentInfo>::iterator iter = stable_partition(students.begin(), students.end(), pgrade);
    vector<StudentInfo> failing_students(iter, students.end());

    // a
    students.erase(iter, students.end());
    return failing_students;
}

// Compute the final grade for a student
double grade(const StudentInfo &s)
{
    return grade(s.midterm, s.final, s.homework);
}

// Calculates the final grade, provided a midterm grade, final exam grade, and a vector of homework grades
double grade(const double midterm, const double final, const vector<double> &homework)
{
    if (homework.size() == 0)
    {
        throw domain_error("Student has done no homework");
    }
    return grade(midterm, final, median(homework));
}

// Applies the correct weighting to the midterm grade, final exam grade, and overall homework grade to calculate final grade
double grade(const double midterm, const double final, const double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// Determines if a student has a failing grade
bool fgrade(const StudentInfo &s)
{
    static const double kLowestPassingGrade = 60;
    return grade(s) < kLowestPassingGrade;
}

// Determines if a student has a passing grade
bool pgrade(const StudentInfo &s)
{
    return !fgrade(s);
}

/*
Reads incoming data.
First string: read as name.
The next two doubles are read as midterm and final grades, respectively.
The remaining double are homework grades.
*/
istream &read(
    istream &stream_in,
    StudentInfo &into)
{
    string name;
    stream_in >> name;
    if (name != "end" && name != "exit")
    {
        into.name = name;
        stream_in >> into.midterm >> into.final;
        read(stream_in, into.homework);
    }
    else
    {
        throw domain_error("Program exit");
    }

    return stream_in;
}

// compare() is to be used as predicate to sort(StudentInfo)
bool compare_by_name(
    const StudentInfo &student_info_x, // The first student in comparison for purposes of sorting
    const StudentInfo &student_info_y  // The second student in comparison for purposes of sorting
)
{
    return student_info_x.name < student_info_y.name;
}
