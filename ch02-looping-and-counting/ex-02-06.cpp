/*
What does the following code do?
int i = 0;
while (i < 10) {
    i += 1;
    std::cout << i << std::endl;
}

Ans: This program prints the numbers 1-10, each on a new line.
*/

#include <iostream>
int i = 0;
int main()
{
    while (i < 10)
    {
        i += 1;
        std::cout << i << std::endl;
    }
}
