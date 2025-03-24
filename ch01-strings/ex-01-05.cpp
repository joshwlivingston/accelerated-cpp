/*
Is this program valid? If so, what does it do? If not, say why not, and rewrite it to be valid.
#include <iostream>
#include <string>
int main()
{
    {
        std::string s = "a string";
        {
            std::string x = s + ", really";
            std::cout << s << std::endl;
        }
        std::cout << x << std::endl;
    }
    return 0;
}

Ans:
This program is not valid as written. The variable x is defined outside the scope in which it is used.
s can be found, since its scope it a superset of the scope in which it is used.

A valid implementation creates x in the scope in which it is printed to the console, and does not
re-create x in the inner-scope.
*/

#include <iostream>
#include <string>

int main()
{
    {
        std::string x;
        std::string s = "a string";
        {
            x = s + ", really";
            std::cout << s << std::endl;
        }
        std::cout << x << std::endl;
    }
    return 0;
}