/*
Accelerated C++: Section 10.4
Providing arguments to main()

Compiled in executable: say.exe

Input:
```
~$ say bruh
```

Output:
```
bruh
```
*/
#include <iostream>

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        int i = 1;
        while (i != argc - 1)
            std::cout << argv[i++] << " "; // print all inputs to console
        std::cout << argv[i] << std::endl; // no space after last input
    }
    return 0;
}
