/*
Rewrite the Student_info structure to calculate the grades immediately and store only the final grade.
*/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "student_info.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main()
{
    // initialize longest_student_name_length so max() is defined
    vector<StudentInfo> students;
    StudentInfo student;
    string::size_type longest_student_name_length = 0;
    try
    {
        while(read(cin, student))
        {
            longest_student_name_length = max(longest_student_name_length, student.name.size());
            students.push_back(student);
        }
    }
    catch (domain_error &e)
    {
        cout << "Calculating grades..." << endl;
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
            cout << setprecision(3) << grade(students[i]) << setprecision(precision_original);
        }
        catch (domain_error e)
        {
            cout << e.what();
        }
        cout << endl;
    }

    return 0;
}
