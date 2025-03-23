/*
We want to write a more elaborate greeting:

Please enter your first name: Estragon

********************
*                  *
* Hello, Estragon! *
*                  *
********************

The program produces five lines of output. 
A sensible strategy is to build the output one piece at a time.
*/
#include <iostream>
#include <string>

int main()
{
    std::cout << "Please enter your name: ";
    std::string name;
    std::cin >> name;

    // = symbol here does implicit conversion (string literal --> string)
    // + operator is overloaded for strings
    // here, + means string concatenation
    
    // "strictly speaking, the program gains nothing by using const"
    // but it enhances understandability
    const std::string greeting = "Hello, " + name + "!";
    const int greeting_size = greeting.size();

    // using parentheses tells program to construct the variable using enclosed expressions
    // greeting.size() is a member function that returns int
    // ' ' is a character literal (with type char) - completely distinct from string literals ('' vs "")
    // constructing a string using an int and a char results in a string containing `int` copies of `char`
    const std::string spaces(greeting_size, ' ');

    // second and fourth line
    // string concatentation
    const std:: string second = "* " + spaces + " *";

    // first and fifth line
    // repeat '*' across entire line
    const std::string first(greeting_size, '*');

    // write all output together
    std::cout << std::endl;
    std::cout << "**" << first << "**" << std::endl;
    std::cout << "* " << spaces << " *" << std::endl;
    std::cout << "* " << greeting << " *" << std::endl;
    std::cout << "* " << spaces << " *" << std::endl;
    std::cout << "**" << first << "**" << std::endl;

    return 0;
}
