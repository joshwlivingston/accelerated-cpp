/*
Is the following program valid? If so, what does it do? If not, why not?

#include <iostream>
#include <string>
int main()
{
    { const std::string s = "a string";
        std::cout << s << std::endl; }
    { const std::string s = "another string";
        std::cout << s << std::endl; }
    return 0;
}

Ans: Yes, the program is valid. the const s is defined in separate scopes,
  so there is no issue with the two const creations. The program prints:

a string
another string
*/

#include <iostream>
#include <string>

int main()
{
    {
        const std::string s = "a string";
        std::cout << s << std::endl;
    }
    {
        const std::string s = "another string";
        std::cout << s << std::endl;
    }
    return 0;
}
