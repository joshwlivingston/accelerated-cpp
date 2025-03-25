/*
What happens if we rewrite the previous program to allow values up to but not including
1000 but neglect to change the arguments to setw? Rewrite the program to be more robust in
the face of changes that allow i to grow without adjusting the setw arguments.
*/

#include <algorithm>
#include <iomanip>
#include <iostream>

using std::cout;
using std::endl;
using std::max;
using std::setw;
using std::streamsize;

int size(const int x)
{
    int size = 1;
    int i = 1;
    while (i % x != 0) // i = 10 ^ size, where size is <= the number of digits in x. `size` cannot exceed the digits in x
    {
        ++size;
        i *= 10;
    }

    return size;
}

int main()
{
    const int kIntStart = 1;
    const int kIntEnd = 10;
    const int int_max = max(kIntStart, kIntEnd);
    const int increment = kIntEnd == int_max ? 1 : -1;

    const int column_size_l = size(int_max);
    const int column_size_r = size(int_max * int_max) + 1;

    // sequence through set start and end
    for (int i = kIntStart; i != kIntEnd + increment; i += increment)
    {
        cout << setw(column_size_l) << i << setw(column_size_r) << i * i << endl;
    }

    return 0;
}
