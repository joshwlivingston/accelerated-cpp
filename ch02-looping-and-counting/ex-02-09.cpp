/*
Write a program that asks the user to enter two numbers and tells the
user which number is larger than the other.
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    double number1;
    cout << "Enter the first number: ";
    cin >> number1;

    double number2;
    cout << "Enter the second number: ";
    cin >> number2;

    const string is_larger_than = " is larger than ";
    if (number2 > number1)
    {
        cout << number2 << is_larger_than << number1 << endl;
        return 0;
    }

    cout << number1;
    if (number1 == number2)
    {
        cout << " is equal to ";
    }
    else
    {
        cout << is_larger_than;
    }
    cout << number2 << endl;

    return 0;
}
