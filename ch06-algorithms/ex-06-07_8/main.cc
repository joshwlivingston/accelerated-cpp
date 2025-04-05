#include <iostream>
#include <stdexcept>
#include <vector>

#include "student_info.h"

using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::vector;

int main()
{
    vector<StudentInfo> students_who_did_all_homework;
    vector<StudentInfo> students_who_did_not_do_all_homework;

    vector<StudentInfo> students;
    StudentInfo student;
    try
    {
        while (read(cin, student))
        {
            students.push_back(student);
        }
    }
    catch (domain_error &e)
    {
        cout << endl;
    }

    students_who_did_all_homework = extract(students, did_all_hw);

    cout << endl 
         << "Number of students who did all homework: " << students_who_did_all_homework.size();

         cout << endl 
         << "Number of students who did not do all homework: " << students.size();

    return 0;
}