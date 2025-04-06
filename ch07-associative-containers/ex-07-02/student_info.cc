#include "student_info.h"

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "doublevec.h"
#include "grade.h"

using std::istream;
using std::ostream;
using std::runtime_error;
using std::string;
using std::vector;

char letter_grade(const StudentInfo &student)
{
    return letter_grade(grade(student));
}

// Compute the final grade for a student
double grade(const StudentInfo &s)
{
    return grade(s.midterm, s.final, s.homework);
}

// compare() is to be used as predicate to sort(StudentInfo)
bool compare_by_name(
    const StudentInfo &student_info_x, // The first student in comparison for purposes of sorting
    const StudentInfo &student_info_y  // The second student in comparison for purposes of sorting
)
{
    return student_info_x.name < student_info_y.name;
}

/*
Reads incoming data.
First string: read as name.
The next two doubles are read as midterm and final grades, respectively.
The remaining double are homework grades.
*/
istream &read(
    istream &stream_in,  // Incoming data stream (e.g., `cin`)
    ostream &stream_out, // Incoming data stream (e.g., `cout`)
    StudentInfo &student // Ref to StudentInfo struct to place data into
)
{
    // first, read the studen's name
    string name;
    if (name != "end" && name != "exit")
    {
        student.name = name;
        stream_in >> student.midterm >> student.final;
        read(stream_in, student.homework);
    }
    else
    {
        throw runtime_error("Program exit");
    }

    return stream_in;
}
