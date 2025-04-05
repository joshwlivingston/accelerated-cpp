#include "student_info.h"

#include <algorithm>
#include <ios>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>

#include "doublevec.h" // median()

using std::domain_error;
using std::find;
using std::istream;
using std::stable_partition;
using std::string;
using std::vector;

/*
Removes students matching predicate and copies to output vector.
*/
vector<StudentInfo> extract(
    vector<StudentInfo> &students,
    bool predicate(const StudentInfo &))
{
    // sort input by predicate and return border position
    const vector<StudentInfo>::iterator partition = stable_partition(students.begin(), students.end(), predicate);

    // used returned border position to extract matching elements into new vector
    const vector<StudentInfo> extracted_students(partition, students.end());

    // erase matched elements from input vector
    students.erase(partition, students.end());

    // return matched elements
    return extracted_students;
}

// Checks if a student did all homeworks
bool did_all_hw(const StudentInfo &student)
{
    // find() will return an iterator corresponding to the position of the matching element
    return find(student.homework.begin(), student.homework.end(), 0) == student.homework.end();
}


// Determines if a student has a failing grade
bool fgrade(const StudentInfo &s)
{
    static const double kLowestPassingGrade = 60;
    return grade(s) < kLowestPassingGrade;
}

// Compute the final grade for a student
double grade(const StudentInfo &s)
{
    return grade(s.midterm, s.final, s.homework);
}

// Calculates the final grade, provided a midterm grade, final exam grade, and a vector of homework grades
double grade(const double midterm, const double final, const vector<double> &homework)
{
    if (homework.size() == 0)
    {
        throw domain_error("Student has done no homework");
    }
    return grade(midterm, final, median(homework));
}

// Applies the correct weighting to the midterm grade, final exam grade, and overall homework grade to calculate final grade
double grade(const double midterm, const double final, const double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

/*
Reads incoming data.
First string: read as name.
The next two doubles are read as midterm and final grades, respectively.
The remaining double are homework grades.
*/
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
