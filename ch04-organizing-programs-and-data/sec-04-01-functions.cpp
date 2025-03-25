/*
Notes:

Important qualities of library facilities:
1. Solves a particular kind of problem
2. Is independent of most other facilities
3. Has a name

c++ offers three primary methods for organizing problems:
1. Functions (sometimes called subroutines)
2. Data structures
3. Separate files

Two advantages of functions:
1. Reduces effort - no need to rewrite the computation explcitily multiple times
2. Easier to change - only have to change in one place
3. Naming computations allows for abstracted thinking.
    - First, identify the important steps of the computation
    - Then, create named pieces corresponding to those steps

The task is to rewrite the grade calculation from previous chapter into its own function.

Then, I can write a main() function to create a program that uses the function.
*/

#include <ios>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::setprecision;
using std::streamsize;
using std::vector;

typedef vector<double>::size_type vector_size;

double calculate_median(const vector<double> &vec) // & indicates a reference to the object
{
    const vector_size vec_size = vec.size();
    const vector_size mid = vec_size / 2;
    return vec_size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

double calculate_grade                                                   // function name
    (const double &midterm, const double &final, const double &homework) // parameter list
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double calculate_grade                                                           // function overloading, now homework as vector
    (const double &midterm, const double &final, const vector<double> &homework) // const reference is a read-only reference
{
    if (homework.size() == 0)
    {
        throw domain_error("Student has done no homework");
    }
    return calculate_grade(midterm, final, calculate_median(homework));
}

int main()
{
    const streamsize precision_original = cout.precision();

    cout << "Enter midterm and final grades:" << endl;
    double midterm, final;
    cin >> midterm >> final;

    cout << endl
         << "Enter homework grades (enter any non-number to stop entering grades):" << endl;
    vector<double> homework;
    double grade_input = 0;
    while (cin >> grade_input) // Invariant: all grades provided have been read into homework
    {
        homework.push_back(grade_input);
    }

    cout << endl
         << "The final grade is "
         << setprecision(3)
         << calculate_grade(midterm, final, homework)
         << setprecision(precision_original)
         << "."
         << endl;
    return 0;
}
