/*
Demonstrate using multiple headers

Notes:
Including the headers means both declarations (from the headers), and the defintions (from below) are both included.

This is a harmless redundancy, and gives the compiler the opportunity to verify consistency between declarations and defintions.

Grouping the delcarations together into the header file allows for easy comparison of alternatives.
*/

#include "grade.h"
#include "median.h"
#include "read.h"
#include "student_info.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::istream;
using std::max;
using std::setprecision;
using std::streamsize;
using std::string;
using std::vector;

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
istream &read(          // No ambiguity in naming function read(), since the second parameter dictates what is read by this function
    istream &stream_in, // Incoming data stream (e.g., `cin`)
    StudentInfo &into   // Ref to StudentInfo struct to place data into
)
{
    stream_in >> into.name >> into.midterm >> into.final;
    read(stream_in, into.homework);
    return stream_in;
}

// Calculates the final grade for a provided student
double grade(const StudentInfo &student_info) // A student of type StudentInfo
{
    return grade(student_info.midterm, student_info.final, student_info.homework);
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

int main()
{
    vector<StudentInfo> students;
    StudentInfo student;
    string::size_type longest_student_name_length = 0;

    while (read(cin, student))
    {
        longest_student_name_length = max(longest_student_name_length, student.name.size());
        students.push_back(student);
    }

    // sort students alphabetically by name
    sort(students.begin(), students.end(), compare_by_name);

    cout << endl;
    for (vector<StudentInfo>::size_type i = 0; i != students.size(); ++i)
    {
        // Right-pad name left-align grade 'column'
        cout << students[i].name
             << string(longest_student_name_length + 1 - students[i].name.size(), ' ');
        try
        {
            const streamsize precision_original = cout.precision();
            double final_grade = grade(students[i]);
            cout << setprecision(3) << final_grade << setprecision(precision_original);
        }
        catch (domain_error e)
        {
            cout << e.what();
        }
        cout << endl;
    }

    return 0;
}
