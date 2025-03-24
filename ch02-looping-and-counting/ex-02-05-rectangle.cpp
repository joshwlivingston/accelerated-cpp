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
    cout << "Enter the rectangle's height: ";
    string::size_type dim_height;
    cin >> dim_height;
    cout << endl;

    cout << "Enter the rectangle's width: ";
    string::size_type dim_width;
    cin >> dim_width;
    cout << endl;

    string rectangle_row(dim_width, '*');
    for (int i = 0; i != dim_height; ++i)
    {
        cout << rectangle_row;
        cout << endl;
    }
    
    return 0;
}
