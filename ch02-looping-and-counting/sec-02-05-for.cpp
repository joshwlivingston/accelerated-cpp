#include <iostream>
#include <string>

// declare cout as coming from std namespace
using std::cout;

int main()
{
    const int GREETING_PADDING = 5;

    const int rows_total = GREETING_PADDING * 2 + 3;

    cout << "Please enter your name: ";
    std::string name;
    std::cin >> name;

    std::string greeting = "Hello, " + name + "!";
    const std::string::size_type cols_total = greeting.size() + GREETING_PADDING * 2 + 2;

    cout << std::endl;
    
    // standard while loops can be written as for loops
    for (int r = 0; r != rows_total; ++r) {
        std::string::size_type c = 0;
        while (c != cols_total) {

            // the loop has three separate cases, and the code can be simplified to match
            if (r == GREETING_PADDING + 1 && c == GREETING_PADDING + 1) {
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
