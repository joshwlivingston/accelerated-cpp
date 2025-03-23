/*
What about this one? What if we change }} to };} in the third line from the end?
#include <iostream>
#include <string>
int main()
{
    { 
        const std::string s = "a string";
        std::cout << s << std::endl;
        { 
            const std::string s = "another string";
            std::cout << s << std::endl; 
        }
    }
    return 0;
}

Ans: 
Yes, the program is still valid as written, due to the creation of separate scopes using brackets
If we change the third line to };}, the program will still work. Semicolon is optional on a bracket close
*/

#include <iostream>
#include <string>

int main()
{
    { 
        const std::string s = "a string";
        std::cout << s << std::endl;
        { 
            const std::string s = "another string";
            std::cout << s << std::endl; 
        };
    }
    return 0;
}
