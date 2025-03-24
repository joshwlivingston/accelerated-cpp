/*
What does the following program do if, when it asks you for input, you type two names
(for example, Samuel Beckett)? Predict the behavior before running the program, then try it.
#include <iostream>
#include <string>
int main()
{
    std::cout << "What is your name? ";
    std::string name;
    std::cin >> name;
    std::cout << "Hello, " << name
        << std::endl << "And what is yours? ";
    std::cin >> name;
    std::cout << "Hello, " << name
        << "; nice to meet you too!" << std::endl;
    return 0;
}

Ans:

Predicted output:

What is your name? Samuel Beckett
Hello, Samuel Beckett
And what is yours? Samuel Beckett
Hello, Samuel Beckett nice to meet you too!


My prediction was incorrect.
>> will take the whitespace and read the input as two separate inputs.
So, the first cin will flush the first cout,
  and the second cin will automatically flush the second cout.

Actual output:

What is your name? Samuel Beckett
Hello, Samuel
And what is yours? Hello, Beckett; nice to meet you too!

*/

#include <iostream>
#include <string>
int main()
{
    std::cout << "What is your name? ";
    std::string name;
    std::cin >> name;
    std::cout << "Hello, " << name
              << std::endl
              << "And what is yours? ";
    std::cin >> name;
    std::cout << "Hello, " << name
              << "; nice to meet you too!" << std::endl;
    return 0;
}
