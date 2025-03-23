/*
The program in sec-01-02 was built one line at a time. 
This approach has a pitfall, in that each output line is stored in a separate variable.alignas
So, changing any line of output requires rewriting the entire program.

A more flexible approach does not require storing each line in its own variable.
We are able to generate each character of the output seaparately, 
and observe that when a character is outputted, it is no longer needed. 
That is, the character does not need to be stored in a variable.
The exception is the greeting, which is stored as a std::string
*/

#include <iostream>
#include <string>

int main()
{
    std::cout << "Please enter your name: ";

    std::string name;
    std::cin >> name;

    std::string greeting = "Hello, " + name + "!";

    // think of output as rectangular array of characters, writing one row at a time
    // We know how many characters are in a row, but we need to know how many rows we have.
    const int greeting_pad_rows = 1;

    // the number of rows is double the number of padding rows surrounding the greeting,
    //   plus 3 rows (one for each of top, greeting, bottom)
    const int rows_total = greeting_pad_rows * 2 + 3;

    std::cout << std::endl;

    // stating the invariant of a while loop can make the while loop easier to understand
    // to determine that the invariant is correct, the invariant must be true at two places:
    //   1. Just before while tests initially tests its condition
    //   2. Just before reaching the end of the while body

    // invariant: we have written r rows so far
    int r = 0;

    // (1) here, invariant is true, since 0 rows have been written
    while (r != rows_total) {

        // writing a new row makes the invariant false
        std::cout << std::endl;
        
        // (2) incrementing r by one makes the invariant true again
        ++r;
    } 
    // reaching here, we can conclude we wrote rows_total rows

    return 0;
}
