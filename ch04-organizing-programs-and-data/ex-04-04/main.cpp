/*
Now change your squares program to use double values instead of ints. Use
manipulators to manage the output so that the values line up in columns.
*/

#include "size.h"

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::round;
using std::setprecision;
using std::setw;
using std::streamsize;

int size(const double x, const int decimal_places)
{
    const int x_int = x;
    return size(x_int) + 1 + decimal_places;
}

void size(const double x)
{
    throw domain_error("Input `decimal_places` must be provided when x is a double.");
}

int size(const int x)
{
    int size = 1;
    int i = 1;
    while (x / i > 10)
    {
        ++size;
        i *= 10;
    }

    return size;
}

int main()
{
    const int kDecimalPlacesOut = 2;

    cout << "Staring number: ";
    double number_start;
    cin >> number_start;

    cout << "Ending number: ";
    double number_end;
    cin >> number_end;

    const int column_l_precision = size(number_end, kDecimalPlacesOut);
    const int column_l_width = column_l_precision + 1;

    const int column_r_precision = size(number_end * number_end, kDecimalPlacesOut);
    const int column_r_width = column_r_precision + 2;

    if (number_end <= number_start)
    {
        throw domain_error("The ending number must be greater than the starting number. Please try again.");
        return 1;
    }

    double i;
    for (i = number_start; i < number_end; ++i)
    {
        cout << endl

             << setprecision(column_l_precision)
             << setw(column_l_width)

             << i

             << setprecision(column_r_precision)
             << setw(column_r_width)

             << i * i;
    }
    if (i != number_end)
    {
        cout << endl
             << setprecision(column_l_precision)
             << setw(column_l_width)
             << number_end
             << setprecision(column_r_precision)
             << setw(column_r_width)
             << number_end * number_end;
    }

    cout << endl;

    return 0;
}
