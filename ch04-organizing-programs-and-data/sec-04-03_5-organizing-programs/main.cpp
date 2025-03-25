// Demonstrate the median() function defined in median.h
#include "median.h"

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    cout << "Enter some numbers:" << endl;

    vector<double> numbers;
    double number;
    while(cin >> number)
    {
        numbers.push_back(number);
    }

    cout << endl 
         << numbers[0];

    cout << endl 
         << median(numbers);

    return 0;
}
