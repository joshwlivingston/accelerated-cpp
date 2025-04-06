/*
Extend the program in §4.2.3/64 to assign letter grades by ranges:
*/
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "student_info.h"

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::runtime_error;
using std::setprecision;
using std::streamsize;
using std::string;
using std::vector;

int main()
{
    // initialize longest_student_name_length so max() is defined
    string::size_type longest_student_name_length = 0;
    vector<StudentInfo> students;
    StudentInfo student;
    try
    {
        while (read(cin, cout, student))
        {
            longest_student_name_length = max(longest_student_name_length, student.name.size());
            students.push_back(student);
        }
    }
    catch (runtime_error &e)
    {
        cout << endl;
    }

    // sort students alphabetically by name
    sort(students.begin(), students.end(), compare_by_name);

    cout << endl;

    return 0;
}
