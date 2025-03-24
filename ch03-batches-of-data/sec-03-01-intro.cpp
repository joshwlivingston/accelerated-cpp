/*
Imagine a course in which each student's final exam counts for 40% of the final grade, the
midterm exam counts for 20%, and the average homework grade makes up the remaining
40%. Here is our first try at a program that helps students compute their final grades:
*/

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;         // endl is a manipulator, but it is so common that it appears in iostream and not iomanip
using std::setprecision; // iomanip library to manipulate output
using std::streamsize;   // ios library uses this type to represent sizes
using std::string;

int main()
{
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    cout << endl
         << "Please enter your midterm and final grades:" << endl;
    double midterm, final; // double should always be used instead of float
    cin >> midterm >> final;

    // two or more string literals separated by whitespace are automatically concatenated
    cout << endl
         << "Enter your homework grades, "
            "followed by end-of-file:"
         << endl;
    int count = 0;  // local built-in types do not have a default initialization
    double sum = 0; // if not defined, the are initialized as undefined
    double x;

    // run loop as long as cin >> x succeeds
    while (cin >> x) // cin has type istream, and types have definitions for if and while behavior
    {
        ++count;
        sum += x;
    }

    streamsize prec = cout.precision();
    cout << endl
         << "Your final grade is "
         << setprecision(3) // set precision to three decimals. e.g. 10.1, 99.4
         << 0.2 * midterm + 0.4 * final + 0.4 * sum / count
         << setprecision(prec) // reset precision to original value
         << endl;

    return 0;
}
