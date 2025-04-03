/*
Write a function named `center(const vector<string>&)` that returns a picture
in which all the lines of the original picture are padded out to their full
width, and the padding is as evenly divided as possible between the left and
right sides of the picture.
*/
#include <iostream>
#include <string>

#include "strvec.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

int main()
{
    strvec strings;
    string line;
    while (getline(cin, line))
    {
        strings.push_back(line);
    }

    const strvec centered_picture = center(strings);
    cout << "Centered output:" << endl;
    for (strvec::const_iterator it = centered_picture.begin(); it != centered_picture.end(); ++it)
    {
        cout << *it << endl;
    }

    return 0;
}
