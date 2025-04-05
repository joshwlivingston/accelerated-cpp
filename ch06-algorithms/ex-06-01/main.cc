#include <iostream>
#include <string>

#include "frame.h"
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

    const strvec frame_lines = frame(strings);
    cout << "Framed output:" << endl;
    for (strvec::const_iterator it = frame_lines.begin(); it != frame_lines.end(); ++it)
    {
        cout << *it << endl;
    }

    const strvec vcat_out = vcat(strings, frame_lines);
    cout << endl
         << "Vertically concatenated (1/2):" << endl;    
    for (strvec::const_iterator it = vcat_out.begin(); it != vcat_out.end(); ++it)
    {
        cout << *it << endl;
    }

    const strvec vcat_out2 = vcat(frame_lines, strings);
    cout << endl
         << "Vertically concatenated (2/2):" << endl;    
    for (strvec::const_iterator it = vcat_out2.begin(); it != vcat_out2.end(); ++it)
    {
        cout << *it << endl;
    }

    const strvec hcat_out = hcat(strings, frame_lines);
    cout << endl
         << "Horizontally concatenated (1/2):" << endl;    
    for (strvec::const_iterator it = hcat_out.begin(); it != hcat_out.end(); ++it)
    {
        cout << *it << endl;
    }

    const strvec hcat_out2 = hcat(frame_lines, strings);
    cout << endl
         << "Horizontally concatenated (2/2):" << endl;    
    for (strvec::const_iterator it = hcat_out2.begin(); it != hcat_out2.end(); ++it)
    {
        cout << *it << endl;
    }

    return 0;
}
