/*
Change the framing program so that it uses a different amount of space to separate the 
sides from the greeting than it uses to separate the top and bottom borders from the greeting.
*/

#include <iostream>
#include <string>

using std::cout;

int main()
{
    // set program constants for padding surroundg greeting
    const int GREETING_PADDING_ROWS = 1;
    const int GREETING_PADDING_COLUMNS = 10;

    const int rows_total = GREETING_PADDING_ROWS * 2 + 3;

    cout << "Please enter your name: ";
    std::string name;
    std::cin >> name;

    std::string greeting = "Hello, " + name + "!";
    const std::string::size_type cols_total = greeting.size() + GREETING_PADDING_COLUMNS * 2 + 2;

    cout << std::endl;
    
    // standard while loops can be written as for loops
    for (int r = 0; r != rows_total; ++r) {
        std::string::size_type c = 0;
        while (c != cols_total) {

            // the loop has three separate cases, and the code can be simplified to match
            if (r == GREETING_PADDING_ROWS + 1 && c == GREETING_PADDING_COLUMNS + 1) {
                // 1: we are going to write the whole greeting
                cout << greeting;
                c += greeting.size();
            } else {
                if (r == 0 || r == rows_total - 1 || c == 0 || c == cols_total - 1) {
                    // 2. we are in a border and going to write an asterisk
                    cout << "*";
                } else {
                    // 3. we are whitespace
                    cout << " ";
                }
                ++c;
            }
        }
        cout << std::endl;
    }
    return 0;
}