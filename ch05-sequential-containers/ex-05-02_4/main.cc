/*
Use lists instead of vectors, optimizing specifically for extract_fails()

Optimization improvemetns (from book):

file_size list vector
      735  0.1    0.1
    7,350  0.8    6.7
   73,500  8.8  597.1
*/

#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>

#include "grade.h"
#include "median.h"
#include "read.h"
#include "student_info.h"

using std::cerr;
using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::exception;
using std::list;
using std::max;
using std::printf;
using std::setprecision;
using std::streamsize;
using std::string;
using std::time_t;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;
using std::chrono::steady_clock;

int main()
{
    Students students;
    StudentInfo student;
    string::size_type longest_student_name_length = 0;

    try
    {
        while (read(cin, student))
        {
            longest_student_name_length = max(longest_student_name_length, student.name.size());
            students.push_back(student);
        }
    }
    catch (const domain_error &e)
    {
        cout << endl;
    }

    const steady_clock::time_point begin = steady_clock::now();

    Students students_failed = extract_fails(students);
    cout << endl
         << "Passing Students: " << endl;
    for (Students::const_iterator it = students.begin(); it != students.end(); ++it)
    {
        cout << it->name << endl;
    }

    cout << endl
         << "Failing Students: " << endl;

    for (Students::const_iterator it = students_failed.begin(); it != students_failed.end(); ++it)
    {
        cout << it->name << endl;
    }

    const steady_clock::time_point end = steady_clock::now();

    cout << "Time difference: " << duration_cast<nanoseconds>(end - begin).count() << "[µs]" << endl;

    return 0;
}
