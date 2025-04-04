#include "student_info.h"

#include <ios>
#include <stdexcept>
#include <string>
#include <vector>

#include "doublevec.h"
#include "median.h"

using std::domain_error;
using std::istream;
using std::ostream;
using std::string;
using std::vector;

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

// compare() is to be used as predicate to sort(StudentInfo)
bool compare_by_name(
    const StudentInfo &student_info_x, // The first student in comparison for purposes of sorting
    const StudentInfo &student_info_y  // The second student in comparison for purposes of sorting
)
{
    return student_info_x.name < student_info_y.name;
}

double fgrade(const StudentInfo &s)
{
    static const double kLowestPassingGrade = 60;
    return grade(s) < kLowestPassingGrade;
}

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
