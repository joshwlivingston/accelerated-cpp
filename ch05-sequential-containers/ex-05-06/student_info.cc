#include "student_info.h"

#include <ios>
#include <stdexcept>
#include <string>

#include "grade.h"
#include "read.h"

using std::domain_error;
using std::istream;
using std::string;

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

double fgrade(const StudentInfo &student)
{
    return grade(student) < 60;
}

double grade(const StudentInfo &student_info)
{
    return grade(student_info.midterm, student_info.final, student_info.homework);
}
