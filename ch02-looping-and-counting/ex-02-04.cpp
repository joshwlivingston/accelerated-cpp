/*
The framing program writes the mostly blank lines that separate the borders from the 
greeting one character at a time. Change the program so that it writes all the spaces 
needed in a single output expression.

Ans: I also refactored the nested if-ekse statements into a happier path
*/

#include <iostream>
#include <string>

using std::cout;
using std::cin;

int main()
{
    cout << "Please enter your name: ";
    std::string name;
    cin >> name;
    std::string greeting = "Hello, " + name + "!";
    const std::string::size_type greeting_size = greeting.size();

    cout << "How much vertical padding would you like? ";
    int greeting_padding_rows;    
    cin >> greeting_padding_rows;
    const int rows_total = greeting_padding_rows * 2 + 3;
    const int bottom_row = rows_total - 1;
    const int greeting_row_start = greeting_padding_rows + 1;

    cout << "How much horizontal padding would you like? ";
    int greeting_padding_columns;    
    cin >> greeting_padding_columns;    
    const std::string::size_type cols_total = greeting_size + greeting_padding_columns * 2 + 2;
    const std::string::size_type last_col = cols_total - 1;
    const std::string::size_type n_spaces = cols_total - 2;
    const int greeting_column_start = greeting_padding_columns + 1;

    cout << std::endl;

    for (int r = 0; r != rows_total; ++r) {
        if (r == 0 || r == bottom_row) {
            // 1. Top or bottom row - row border
            const std::string border(cols_total, '*');
            cout << border << std::endl;
            continue;
        }

        std::string::size_type c = 0;
        // invariant: we have written c characters in the current row
        while (c != cols_total) {
            if (c == 0 || c == last_col) {
                // 2. First or last column - column border
                cout << "*";
                ++c;
                continue;
            }

            if (r == greeting_row_start) {
                // We are in row with greeting
                if (c == greeting_column_start) {
                    // 3. Start of the greeting
                    cout << greeting;
                    c += greeting_size;
                } else {
                    // 4. Horizontal whitespace next to greeting
                    const std::string whitespace(greeting_padding_columns, ' ');
                    cout << whitespace;
                    c += greeting_padding_columns;
                }
                continue;                
            }

            // 5. Otherwise, we are full-row whitespace
            const std::string whitespace(n_spaces, ' ');
            cout << whitespace;
            c += n_spaces;
        }
        cout << std::endl;
        
    }
    return 0;
}
