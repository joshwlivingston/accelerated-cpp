/*
Rewrite the Student_info structure to calculate the grades immediately and store only the final grade.
*/

#include "grade.h"
#include "median.h"
#include "iodoublevec.h"
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
using std::ostream;
using std::setprecision;
using std::sort;
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
istream &read(
    istream &stream_in,  // Incoming data stream (e.g., `cin`)
    ostream &stream_out, // Incoming data stream (e.g., `cout`)
    StudentInfo &student   // Ref to StudentInfo struct to place data into
)
{
    // first, read the studen's name
    stream_in >> student.name;

    // second, read the midterm exam grade
    double midterm_grade;
    stream_in >> midterm_grade;

    // then, read the final exam grade
    double final_grade;
    stream_in >> final_grade;

    // Last, read the stream of homework grades
    vector<double> homework_grades;
    read(stream_in, homework_grades);

    try
    {
        student.final_grade = grade(midterm_grade, final_grade, homework_grades);
    }
    catch (domain_error e)
    {
        stream_out << e.what();
    }
    

    return stream_in;
}

// Read a stream of doubles into a vector
std::istream &read(
    std::istream &stream_in,  // Incoming data stream (e.g., `cin`)
    std::vector<double> &into // A reference to the vector to hold the doubles. Will be cleared if not-empty.
)
{
    if (stream_in) // Do not attempt to read non existent data
    {
        // Discard contents of referenced vector, if provided
        into.clear();

        double input_current;
        while (stream_in >> input_current)
        {
            into.push_back(input_current);
        }

        // reset error indications so stream may continue
        stream_in.clear();
    }
    return stream_in;
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

// Returns the median of a vector of doubles
double median(
    // The input vector to calculate the median of
    std::vector<double> vec)
{
    // The size of the input vector
    const vector_size vec_size = vec.size();

    if (vec_size == 0)
    {
        throw std::domain_error("Input to median() must be a double vector with at least one value");
    }

    // The midpoint of the input vector
    const vector_size mid = vec_size / 2;

    sort(vec.begin(), vec.end());

    return vec_size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

int main()
{
    // initialize longest_student_name_length so max() is defined
    vector<StudentInfo> students;
    StudentInfo student;
    string::size_type longest_student_name_length = 0;
    while(read(cin, cout, student))
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
            cout << setprecision(3) << students[i].final_grade << setprecision(precision_original);
        }
        catch (domain_error e)
        {
            cout << e.what();
        }
        cout << endl;
    }

    return 0;
}
