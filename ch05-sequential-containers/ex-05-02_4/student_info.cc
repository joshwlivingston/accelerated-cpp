#include "student_info.h"

#include <ios>

#include "grade.h"
#include "read.h"

using std::istream;

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

/*
Use a list instead of a vector

- The *only* change here is changing the types
*/
Students extract_fails(Students &students)
{
    Students fail;
    Students::const_iterator iter = students.begin();

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
