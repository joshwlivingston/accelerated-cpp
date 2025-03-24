/*
Rewrite the framing program to ask the user to supply the amount of spacing to leave between
the frame and the greeting.
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;

int main()
{
    cout << "Please enter your name: ";
    std::string name;
    cin >> name;
    std::string greeting = "Hello, " + name + "!";

    // input for vertical spacing around greeting
    cout << "How much vertical padding would you like? ";
    int greeting_padding_rows;
    cin >> greeting_padding_rows;
    const int rows_total = greeting_padding_rows * 2 + 3;

    // input for horizontal spacing around greeting
    cout << "How much horizontal padding would you like? ";
    int greeting_padding_columns;
    cin >> greeting_padding_columns;
    const std::string::size_type cols_total = greeting.size() + greeting_padding_columns * 2 + 2;

    cout << std::endl;

    for (int r = 0; r != rows_total; ++r)
    {
        std::string::size_type c = 0;
        // invariant: we have written c characters in the current row
        while (c != cols_total)
        {
            if (r == greeting_padding_rows + 1 && c == greeting_padding_columns + 1)
            {
                // we are at the start of the greeting
                cout << greeting;
                c += greeting.size();
            }
            else
            {
                if (r == 0 || r == rows_total - 1 || c == 0 || c == cols_total - 1)
                {
                    // we are in a border position
                    cout << "*";
                }
                else
                {
                    // we are in a whitespace position
                    cout << " ";
                }
                ++c;
            }
        }
        cout << std::endl;
    }
    return 0;
}