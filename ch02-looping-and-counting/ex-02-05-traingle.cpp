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

    cout << "Enter the traingle's side's length: ";
    string::size_type dim_length;
    cin >> dim_length;    
    
    while (dim_length % 2 == 0 || dim_length == 1)
    {
        if (counter == MAX_TRIES) {
            cout << endl << "Max attempts reached. Exiting program." << endl;
            return 1;
        }

        cout << "Please enter an odd number > 1 for the traingle's side's length: ";
        cin >> dim_length;
        ++counter;
    }

    const string::size_type padding_side_extra = (dim_length - 2) / 2 + 1;

    string::size_type whitespace_middle_length = 1;
    string::size_type whitespace_side_length = dim_length / 2 + padding_side_extra;
    for (int i = 0; i != dim_length; ++i)
    {
        if (i == 0) {
            // top row
            const string whitespace(whitespace_side_length, ' ');
            cout << whitespace << "*" << endl;
            whitespace_side_length -= 1;
            continue;
        }

        if (i == dim_length - 1) {
            // bottom row
            for (int j = 0; j != dim_length - 1; ++j)
            {
                cout << "* ";
            }
            cout << "*" << endl;
            break;
        }

        const string whitespace_side(whitespace_side_length, ' ');
        const string whitespace_middle(whitespace_middle_length, ' ');

        cout << whitespace_side << "*" << whitespace_middle << "*" << endl;

        whitespace_side_length -= 1;
        whitespace_middle_length += 2;
    }
    
    return 0;
}
