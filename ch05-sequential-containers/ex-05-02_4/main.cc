/*
Use lists instead of vectors, optimizing specifically for extract_fails()

Optimization improvemetns (from book):

file_size list vector
      735  0.1    0.1
    7,350  0.8    6.7
   73,500  8.8  597.1
*/

#include <algorithm>
#include <stdexcept>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>

#include "grade.h"
#include "median.h"
#include "read.h"
#include "student_info.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::list;
using std::max;
using std::setprecision;
using std::streamsize;
using std::string;


int main()
{
    // change type from <vector> to <list>
    list<StudentInfo> students;
    StudentInfo student;
    string::size_type longest_student_name_length = 0;

    while (read(cin, student))
    {
        longest_student_name_length = max(longest_student_name_length, student.name.size());
        students.push_back(student);
    }

    // std::sort() does not support lists
    students.sort(compare_by_name);

    cout << endl;
    // use iterator instead of indices
    list<StudentInfo>::const_iterator iter = students.begin();
    while (iter != students.end())
    {
        cout << iter->name
             << string(longest_student_name_length + 1 - iter->name.size(), ' ');
        try
        {
            const streamsize precision_original = cout.precision();
            double final_grade = grade(*iter);
            cout << setprecision(3) << final_grade << setprecision(precision_original);
        }
        catch (domain_error e)
        {
            cout << e.what();
        }
        cout << endl;
    }

    list<StudentInfo> students_failed = extract_fails(students);
    cout << endl
         << "Passing Students: " << endl;
    // use iterator instead of indices
    for (iter = students.begin(); iter != students.end(); ++iter)
    {
        cout << iter->name << endl;
    }

    cout << endl
         << "Failing Students: " << endl;

    // use iterator instead of indices
    for (iter = students_failed.begin(); iter != students_failed.end(); ++iter)
    {
        cout << iter->name << endl;
    }

    return 0;
}
