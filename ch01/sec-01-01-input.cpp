/*
First example in Chapter 1
Ask for a person's name, and greet the person
*/

#include <iostream>
#include <string>

int main()
{
    // ask for person's name
    std::cout << "Please enter your first name: ";

    // define name variable
    std::string name; 

    // read into name variable as string
    // std:: string trims whitespace
    // std:: cin flushes the cout buffer, guaranteeing user sees cout
    std::cin >> name;

    // write a greeting
    // std::cout flushes the cin buffer
    std::cout << "Hello, " << name << "!" << std::endl;
    
    return 0;
}
