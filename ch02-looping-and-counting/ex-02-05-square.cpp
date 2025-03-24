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
    cout << "Enter the square's dimension: ";
    string::size_type square_dim;
    cin >> square_dim;
    cout << endl;

    string square_row(square_dim, '*');
    for (int i = 0; i != square_dim; ++i)
    {
        cout << square_row;
        cout << endl;
    }

    return 0;
}
