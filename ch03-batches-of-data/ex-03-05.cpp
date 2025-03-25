/*
Write a program that will keep track of grades for several students at once. The program
could keep two vectors in sync: The first should hold the student's names, and the second the
final grades that can be computed as input is read. For now, you should assume a fixed
number of homework grades. We'll see in §4.1.3/56 how to handle a variable number of
grades intermixed with student names.
*/

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::streamsize;
using std::string;
using std::vector;

int main()
{
    const int NUM_HW_GRADES = 3;

    vector<string> students;
    vector<double> grades;

    bool run_program = true;
    const string run_program_flag = "y";
    while (run_program)
    {
        cout << "Please enter the student's name: ";
        string name;
        cin >> name;
        cout << "Hello, " << name << "!" << endl;

        cout << endl
             << "Please enter " << name << "'s midterm and final grades:" << endl;
        double midterm, final; // double should always be used instead of float
        cin >> midterm >> final;

        // two or more string literals separated by whitespace are automatically concatenated
        cout << endl
             << "Enter " << name << "'s " << NUM_HW_GRADES << " homework grades:"
             << endl;

        double sum = 0;
        double x;

        // run loop as long as cin >> x succeeds
        for (int i = 0; i < NUM_HW_GRADES; ++i)
        {
            cin >> x;
            sum += x;
        }

        students.push_back(name);
        grades.push_back(0.2 * midterm + 0.4 * final + 0.4 * sum / 3);

        cout << endl
             << "\"y\" to add another student-grade: ";
        string res;
        cin >> res;
        cout << endl;
        run_program = res == run_program_flag;
    }

    streamsize precision_original = cout.precision();
    cout << setprecision(3);

    typedef vector<string>::size_type vector_size;
    vector_size number_of_students = students.size();

    cout << "Final grades:" << endl;
    for (vector_size i = 0; i < number_of_students; ++i)
    {
        cout << endl
             << "Student: " << students[i] << endl
             << "Grade: " << grades[i] << endl;
    }
    cout << setprecision(precision_original) << endl;

    return 0;
}
