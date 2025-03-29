/*
An iterator has the following properties:
- It identifies a container and an element in the container
- It allows us to examine the value store in that element
- It provides operations for moving between elements in the container
- It restrics available operations to what the container can efficiently handle

Using an index for iteration:
```cpp
for (vector<StudentInfo>::size_type 1 = 0; i != students.size(); ++i)
{
    cout << students[i].name << endl;
}
```

Using an iterator for iteration:
```cpp
for (vector<StudentInfo>::const_iterator iter = students.begin(); iter != students.end() ++iter;)
{
    cout << (*iter).name << endl;
}
```

Every standard container, e.g. `vector`, defines two iterator types:
1. Read only access `container::const_iterator`
2. Read + Write access `container::iterator`

- `begin()` and `end()` functions return a value of the same iterator type for the container.
- `+` increments the iterator
- `*` is the dereference operator. Applied to an iterator, it returns an lvalue which is the element to which the iterator refers
- The parentheses are required in `(*iter).name` because `.` has a higher precedence than `*`.
- `(*iter).prop` can be written as `iter->prop`
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

// Read a stream of doubles into a vector
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
Use an iterator instead of indices
*/
vector<StudentInfo> extract_fails(vector<StudentInfo> &students)
{
    vector<StudentInfo> fail;

    // user read-only iterator
    vector<StudentInfo>::const_iterator iter = students.begin();

    while (iter != students.end())
    {
        if (fgrade(*iter) < 60)
        {
            fail.push_back(*iter);

            // all iterators referring to elements after the modified value of a vector become invalidated
            // .erase() returns an iterator of the same type, now validated
            // newly returned iterator starts at element following the one that was erased
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
    vector<StudentInfo> students;
    StudentInfo student;
    string::size_type longest_student_name_length = 0;

    while (read(cin, student))
    {
        longest_student_name_length = max(longest_student_name_length, student.name.size());
        students.push_back(student);
    }

    sort(students.begin(), students.end(), compare_by_name);

    cout << endl;
    for (vector<StudentInfo>::size_type i = 0; i != students.size(); ++i)
    {
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

    vector<StudentInfo> students_failed = extract_fails(students);

    cout << endl
         << "Passing Students: " << endl;
    for (vector<StudentInfo>::size_type i = 0; i != students.size(); ++i)
    {
        cout << students[i].name << endl;
    }

    cout << endl
         << "Failing Students: " << endl;
    for (vector<StudentInfo>::size_type i = 0; i != students_failed.size(); ++i)
    {
        cout << students_failed[i].name << endl;
    }

    return 0;
}
