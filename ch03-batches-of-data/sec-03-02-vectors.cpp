/*
The program that we've written so far has a design shortcoming: It throws away each homework
grade as soon as it has read it. Doing so is fine for computing averages, but what if we wanted to
use the median homework grade instead of the average?
*/

#include <algorithm> // sort()
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

// vectors are defined using a template class, so the object's type can be seaprated from the object's contents' type
using std::vector;

int main()
{
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    cout << endl
         << "Please enter your midterm and final grades:" << endl;
    double midterm, final;
    cin >> midterm >> final;

    cout << endl
         << "Enter your homework grades, "
            "followed by end-of-file:"
         << endl;

    double x;
    vector<double> homework;
    while (cin >> x) // invariant: `homework` contains all grades read so far
    {
        homework.push_back(x); // member function that appends to end of vector
    }

    // typedefs can be used to simplify difficult to read/write type definitions
    typedef vector<double>::size_type vector_size;
    vector_size size = homework.size();

    if (size == 0)
    {
        cout << "You must enter your grades. Please try again." << endl;
        return 1;
    }

    // sort() comes from <algorithm> header
    // sort must be no slower than nlog(n), per c++ standards
    // so, entire program is guaranteed to run in nlog(n) time
    sort(homework.begin(), homework.end());

    vector_size mid = size / 2;
    double median;

    // conditional operators
    median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2 : homework[mid];

    // notes on vectors:
    // all elements of a vector have an int index associated with it
    // vectors do not check if an index is in range before attempting to access
    // vector::size_type is an unsigned integer type, meaning they are incapable of storing negative values
    // appends to a vector must be no worse than pre-allocating memory than proportional to number of elements

    streamsize prec = cout.precision();
    cout << endl
         << "Your final grade is "
         << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4 * median
         << setprecision(prec)
         << endl;

    return 0;
}
