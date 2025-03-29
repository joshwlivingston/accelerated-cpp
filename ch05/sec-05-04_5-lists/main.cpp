/*
Use lists instead of vectors, optimizing specifically for extract_fails()

Optimization improvemetns (from book):

file_size list vector
      735  0.1    0.1
    7,350  0.8    6.7
   73,500  8.8  597.1
*/

#include "grade.h"
#include "median.h"
#include "read.h"
#include "student_info.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::istream;
using std::list;
using std::max;
using std::setprecision;
using std::streamsize;
using std::string;
using std::vector;

bool compare_by_name(
    const StudentInfo &student_info_x,
    const StudentInfo &student_info_y)
{
    return student_info_x.name < student_info_y.name;
}

istream &read(
    istream &stream_in,
    StudentInfo &into)
{
    stream_in >> into.name >> into.midterm >> into.final;
    read(stream_in, into.homework);
    return stream_in;
}

std::istream &read(
    std::istream &stream_in,
    std::vector<double> &into)
{
    if (stream_in)
    {
        into.clear();

        double input_current;
        while (stream_in >> input_current)
        {
            into.push_back(input_current);
        }

        stream_in.clear();
    }
    return stream_in;
}

/*
Use a list instead of a vector

- The *only* change here is changing the types
*/
list<StudentInfo> extract_fails(list<StudentInfo> &students)
{
    list<StudentInfo> fail;
    list<StudentInfo>::const_iterator iter = students.begin();

    while (iter != students.end())
    {
        if (fgrade(*iter) < 60)
        {
            fail.push_back(*iter);
            iter = students.erase(iter);
        }
        else
        {
            ++iter;
        }
    }
    return fail;
}

double fgrade(const StudentInfo &student)
{
    return grade(student) < 60;
}

double grade(const StudentInfo &student_info)
{
    return grade(student_info.midterm, student_info.final, student_info.homework);
}

double grade(const double midterm, const double final, const vector<double> &homework)
{
    if (homework.size() == 0)
    {
        throw domain_error("Student has done no homework");
    }
    return grade(midterm, final, median(homework));
}

double grade(const double midterm, const double final, const double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double median(std::vector<double> vec)
{
    const vector_size vec_size = vec.size();

    if (vec_size == 0)
    {
        throw std::domain_error("Input to median() must be a double vector with at least one value");
    }

    const vector_size mid = vec_size / 2;

    sort(vec.begin(), vec.end());

    return vec_size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

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
