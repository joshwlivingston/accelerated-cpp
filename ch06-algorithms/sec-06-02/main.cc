/*
Our aim is to modify the Student grading program so that we may:

1. Read all the student records, separating the students who did all the
   homework from the others.
2. Apply each of the grading schemes to all the students in each group, and
   report the median grade of each group.
*/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "student_info.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main()
{
    vector<StudentInfo> students_who_did_all_homework;
    vector<StudentInfo> students_who_did_not_do_all_homework;

    StudentInfo student;
    try
    {
        while (read(cin, student))
        {
            if (did_all_hw(student))
            {
                students_who_did_all_homework.push_back(student);
            }
            else
            {
                students_who_did_not_do_all_homework.push_back(student);
            }
        }
    }
    catch (domain_error &e)
    {
        cout << "Calculating grades..." << endl;
    }

    if (students_who_did_all_homework.empty())
    {
        cout << "No student did all homeworks!" << endl;
        return 1;
    }

    if (students_who_did_not_do_all_homework.empty())
    {
        cout << "All students did all homeworks!" << endl;
        return 1;
    }

    do_average_grade_by_homework_status(
        cout,
        "median",
        grade_using_median,
        students_who_did_all_homework,
        students_who_did_not_do_all_homework);

    do_average_grade_by_homework_status(
        cout,
        "mean",
        grade_using_mean,
        students_who_did_all_homework,
        students_who_did_not_do_all_homework);

    do_average_grade_by_homework_status(
        cout,
        "median_optimistic",
        grade_using_median_optimistic,
        students_who_did_all_homework,
        students_who_did_not_do_all_homework);

    const vector<StudentInfo> failures = extract_fails(students_who_did_all_homework);
    cout << "Numer of students who did all homework and failed: " << failures.size();

    const vector<StudentInfo> failures_but_more_expected = extract_fails(students_who_did_not_do_all_homework);
    cout << "Number of students who did not do all homework and failed: " << failures_but_more_expected.size();

    return 0;
}
