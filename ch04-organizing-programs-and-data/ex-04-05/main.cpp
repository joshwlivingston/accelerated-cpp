/*
Write a function that reads words from an input stream and stores them in a vector. Use
that function both to write programs that count the number of words in the input, and to count
how many times each word occurred.
*/

#include "iostringvec.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::sort;
using std::string;
using std::vector;

istream &read(istream &stream_in, vector<string> &words)
{
    string word;
    while (stream_in >> word)
    {
        words.push_back(word);
    }
    return stream_in;
}

int main()
{
    vector<string> words;
    cout << "Enter some words:" << endl;
    read(cin, words);
    
    const vector<string>::size_type words_collected = words.size();
    cout << endl
         << "Number of words collected: " << words_collected << endl;

    sort(words.begin(), words.end());

    cout << endl
         << "Count of words collected:" << endl;
    int sum_current = 1;
    for (int i = 0; i != words_collected; ++i)
    {
        if (i == 0)
        {
            continue;
        }

        if (words[i] != words[i - 1] || i == words_collected - 1)
        {
            cout << words[i - 1] << ": " << sum_current << endl;
            sum_current = 1;
            continue;
        }

        ++sum_current;
    }

    return 0;
}
