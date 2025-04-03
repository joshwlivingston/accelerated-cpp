/*
Accelerated C++
Chapter 05 Exercise 09

Write a program to write the lowercase words in the 
input followed by the uppercase words.

Ans:
Since sort() places uppercase words before lowercase words, our program
simply calls sort() then reverse() on the reference vector.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::reverse;
using std::vector;
using std::string;

void sort_by_case(vector<string> &v)
{
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
}

int main()
{
    vector<string> strings;
    string in;
    while(cin >> in)
    {
        strings.push_back(in);
    }

    sort_by_case(strings);
    cout << "Sorted:" << endl;
    for (vector<string>::const_iterator it = strings.begin(); it != strings.end(); ++it)
    {
        cout << *it << endl;
    }

    return 0;
}
