/*
Extend the program in §4.2.3/64 to assign letter grades by ranges:
*/
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>

#include "grade.h"
#include "student_info.h"

using std::cin;
using std::cout;
using std::endl;
using std::move;
using std::runtime_error;
using std::string;

int main()
{
    // initialize longest_student_name_length so max() is defined
    string::size_type longest_student_name_length = 0;
    Students students;
    StudentInfo student;
    try
    {
        while (read(cin, cout, student))
        {
            // use std::move(), from <utility>, to avoid copying data
            students.push_back(move(student));
        }
    }
    catch (runtime_error &e)
    {
        cout << endl;
    }

    CountsByLetterGrade letter_grade_results;
    get_letter_grades(students, letter_grade_results);

    CountsByLetterGrade::const_iterator letter_grade = letter_grade_results.begin();
    while (letter_grade != letter_grade_results.end())
    {
        cout << letter_grade->first << ": " << letter_grade->second << endl;
        ++letter_grade;
    }

    return 0;
}
