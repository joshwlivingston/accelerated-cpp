/*
Write a program to calculate the average of the numbers stored in a vector<double>.
*/

#include "mean.h"

#include <iomanip>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::setprecision;
using std::setw;
using std::size_t;
using std::vector;

double mean(const vector<double> &vec)
{
    const size_t vec_size = vec.size();
    if (vec_size == 0)
    {
        throw domain_error("Input `vec` to `mean()` must have at least one element.");
    }

    double sum = 0;
    for (size_t i = 0; i != vec_size; ++i)
    {
        sum += vec[i];
    }

    return sum / vec_size;
}

int main()
{
    cout << "Enter some numbers:" << endl;
    vector<double> numbers;
    double number;
    while (cin >> number)
    {
        numbers.push_back(number);
    }

    cout << endl
         << "Average: " << setw(11) << setprecision(10) << mean(numbers) << endl;
}
