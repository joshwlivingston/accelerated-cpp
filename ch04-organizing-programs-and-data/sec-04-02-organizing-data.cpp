/*
Tip: Placing comments next to object definitions adds comment to IDE hover on object
*/

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <stdexcept>
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

typedef vector<double>::size_type vector_size;

// Student name and grades
struct StudentInfo
{
    string name;             // Student's name
    double midterm;          // Studnet's midterm grade
    double final;            // Student's final exam grade
    vector<double> homework; // Student's homework scores
};

// compare() is to be used as predicate to sort(StudentInfo)
bool compare(
    const StudentInfo &student_info_x, // The first student in comparison for purposes of sorting
    const StudentInfo &student_info_y  // The second student in comparison for purposes of sorting
)
{
    return student_info_x.name < student_info_y.name;
}

istream &read_homework(
    istream &stream_in,      // Incoming data stream (e.g., `cin`)
    vector<double> &homework // A reference to the vector storing homework grades
)
{
    if (stream_in) // Do not attempt to read non existent data
    {
        // discard contents of homework vector
        homework.clear();

        double grade_input_current;
        while (stream_in >> grade_input_current)
        {
            homework.push_back(grade_input_current);
        }

        // reset error indications so stream may continue
        stream_in.clear();
    }
    return stream_in;
}

// First string: read as name. Next doubles read as midterm and final grades, respectively. Remaining doubles are homework grades.
istream &read(                // No ambiguity in naming function read(), since the second parameter dictates what is read by this function
    istream &stream_in,       // Incoming data stream (e.g., `cin`)
    StudentInfo &student_info // Ref to StudentInfo struct to place data into
)
{
    stream_in >> student_info.name >> student_info.midterm >> student_info.final;
    read_homework(stream_in, student_info.homework);
    return stream_in;
}

double calculate_median(const vector<double> &vec)
{
    const vector_size vec_size = vec.size();
    const vector_size mid = vec_size / 2;
    return vec_size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

double calculate_grade(const double midterm, const double final, const double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double calculate_grade(const double midterm, const double final, const vector<double> &homework)
{
    if (homework.size() == 0)
    {
        throw domain_error("Student has done no homework");
    }
    return calculate_grade(midterm, final, calculate_median(homework));
}

// overload calculate_grade() for StudentInfo struct
double calculate_grade(const StudentInfo &student_info)
{
    return calculate_grade(student_info.midterm, student_info.final, student_info.homework);
}

int main()
{
    vector<StudentInfo> students;
    StudentInfo student;
    string::size_type longest_name_length = 0;

    while (read(cin, student))
    {
        longest_name_length = max(longest_name_length, student.name.size());
        students.push_back(student);
    }

    sort(students.begin(), students.end(), compare);

    cout << endl;
    for (vector<StudentInfo>::size_type i = 0; i != students.size(); ++i)
    {
        cout << students[i].name << string(longest_name_length + 1 - students[i].name.size(), ' ');
        try
        {
            const double final_grade = calculate_grade(students[i]);
            const streamsize precision_original = cout.precision();
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
