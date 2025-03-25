/*
Write a program to count how many times each distinct word appears in its input.
*/

#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::string;
using std::vector;

int main()
{
    // Collect words
    cout << "Enter some words:" << endl;
    vector<string> words;
    string word;
    while (cin >> word) // Invariant: all words read so far have been appened to `words`
    {
        words.push_back(word);
    }

    typedef vector<string>::size_type vector_size;
    vector_size words_collected = words.size();

    // Verify words were collected
    if (words_collected == 0)
    {
        cout << "You must enter at least one word. Please try again." << endl;
        return 1;
    }

    sort(words.begin(), words.end());

    // loop though sorted vector of collected words
    int current_word_count = 0;
    string current_word_being_counted = words[0];
    for (vector_size i = 0; i < words_collected; ++i)
    {
        const string current_word = words[i];
        if (current_word_being_counted != current_word) // new word
        {
            cout << endl
                 << current_word_being_counted << ": " << current_word_count;

            // restart word counter
            current_word_being_counted = current_word;
            current_word_count = 0;
        }
        
        ++current_word_count;

        if (i == words_collected - 1) // last word
        {
            // display final message
            cout << endl
                 << current_word_being_counted << ": " << current_word_count << endl;
        }
    }

    return 0;
}
