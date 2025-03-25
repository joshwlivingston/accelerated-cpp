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
#include <istream>
#include <stdexcept>
#include <vector>

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::istream;
using std::setprecision;
using std::streamsize;
using std::vector;

typedef vector<double>::size_type vector_size;

double calculate_median(const vector<double> &vec) // & indicates a reference to the object.
{
    const vector_size vec_size = vec.size();
    const vector_size mid = vec_size / 2;
    return vec_size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

// usually not worth effort to pass built-in types by reference, per book
double calculate_grade                                                // function name
    (const double midterm, const double final, const double homework) // parameter list
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double calculate_grade                                                         // function overloading, now homework as vector
    (const double midterm, const double final, const vector<double> &homework) // const reference is a read-only reference
{
    if (homework.size() == 0)
    {
        throw domain_error("Student has done no homework");
    }
    return calculate_grade(midterm, final, calculate_median(homework));
}

istream &read_homework(istream &stream_in,       // pass reference to return object as param
                       vector<double> &homework) // reference without const usually signals intent to modify. must pass lvalue no non-const ref
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

int main()
{
    cout << "Enter midterm and final grades:" << endl;
    double midterm, final;
    cin >> midterm >> final;

    cout << endl
         << "Enter homework grades (enter end-of-file to stop):" << endl;
    vector<double> homework;
    read_homework(cin, homework);

    try
    {
        // good rule of thumb to avoid more than one side effect in a single statement
        const streamsize precision_original = cout.precision();
        const double final_grade = calculate_grade(midterm, final, homework);
        cout << endl
             << "The final grade is "
             << setprecision(3) << final_grade << setprecision(precision_original)
             << "."
             << endl;
    }
    catch (domain_error)
    {
        cout << endl
             << "You must enter your grades. Please try again." << endl;
        return 1;
    }

    return 0;
}
