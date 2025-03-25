/*
Write a program to compute and print the quartiles (that is, the quarter of the numbers
with the largest values, the next highest quarter, and so on) of a set of integers.
*/

#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::vector;

int main()
{
    cout << "Enter numbers:" << endl;
    int x;
    vector<int> numbers;
    while (cin >> x)
    {
        numbers.push_back(x);
    }

    typedef vector<int>::size_type vector_size;
    vector_size numbers_collected = numbers.size();

    if (numbers_collected == 0)
    {
        cout << "You must enter numbers. Please try again." << endl;
        return 1;
    }

    const vector_size lower_quartile_index = numbers_collected / 4;
    const vector_size mid_index = numbers_collected / 2;
    // order matters in integer multiplcation and division
    const vector_size upper_quartile_index = numbers_collected * 3 / 4;

    sort(numbers.begin(), numbers.end());

    for (int i = 0; i < numbers_collected; ++i)
    {
        if (i == 0)
        {
            cout << endl
                 << "First quartile:" << endl;
        }

        if (i == lower_quartile_index)
        {
            cout << endl
                 << endl
                 << "Second Quartile:" << endl;
        }

        if (i == mid_index)
        {
            cout << endl
                 << endl
                 << "Third Quartile:" << endl;
        }

        if (i == upper_quartile_index)
        {
            cout << endl
                 << endl
                 << "Fourth Quartile:" << endl;
        }

        cout << numbers[i];

        if (i != lower_quartile_index - 1 && i != mid_index - 1 && i != upper_quartile_index - 1 && i != numbers_collected - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;
}
