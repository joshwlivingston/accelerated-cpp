#include <iostream>
#include <string>

int main()
{
    std::cout << "Please enter your name: ";
    std::string name;
    std::cin >> name;
    std::string greeting = "Hello, " + name + "!";
    const int greeting_padding = 1;
    const int rows_total = greeting_padding * 2 + 3;

    // using std::string::size_type is ideal for storing the length of a string
    // using int is possible; however, int as a maximum of 32767. So, theoretically, int is not sufficient
    // it's best practice to use the library's defined type for the given purpose
    const std::string::size_type cols_total = greeting.size() + greeting_padding * 2 + 2;


    std::cout << std::endl;
    int r = 0;
    while (r != rows_total) {
        std::string::size_type c = 0;

        // invariant: we have written c characters in the current row
        while (c != cols_total) {
            std::string out;

            // || is left-associative (like <<) and does not evaluate RHS if LHS is true
            // not evaluating RHS on LHS true is called short-circuit evaluation
            if (r == 0 || r == rows_total - 1 || c == 0 || c == cols_total - 1) {
                out = "*";
            } else {
                // write one or more nonborder characters
                if (r == greeting_padding + 1 && c == greeting_padding + 1) {
                    // this is the first character in the greeting
                    out = greeting;
                } else {
                    out = " ";
                }
            }
            std::cout << out;
            c += out.size();
        } // we have written cols_total characters in the current row

        std::cout << std::endl;
        ++r;
    }

    return 0;
}
