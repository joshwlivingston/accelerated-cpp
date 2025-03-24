/*
Write a set of "*" characters so that they form a square, a rectangle, and a triangle.
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() 
{
    const int MAX_TRIES = 5;
    int counter = 0;

    string::size_type dim_length = 0;
    // throws std::length_error on non-integer || <= 1
    cout << "Enter the traingle's side's length: ";
    cin >> dim_length;

    string::size_type dim_last_index = dim_length - 1;
    string::size_type whitespace_side_length = dim_last_index;

    // top row
    const string whitespace(whitespace_side_length, ' ');
    cout << whitespace << "*" << endl;
    whitespace_side_length -= 1;

    // middle rows
    string::size_type whitespace_middle_length = 1;
    
    for (int i = 1; i != dim_last_index; ++i)
    {
        const string whitespace_side(whitespace_side_length, ' ');
        const string whitespace_middle(whitespace_middle_length, ' ');

        cout << whitespace_side << "*" << whitespace_middle << "*" << endl;

        whitespace_side_length -= 1;
        whitespace_middle_length += 2;
    }

    // bottom row
    for (int i = 0; i != dim_last_index; ++i)
    {
        cout << "* ";
    }
    cout << "*" << endl;
    
    return 0;
}
