/*
Write a program to report the length of the longest and shortest string in its input.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::string;
using std::vector;

typedef vector<string>::size_type vector_size;
typedef string::size_type string_size;

int main()
{
    // Collect words
    vector<string> words;
    string word;
    cout << "Please enter some words:" << endl;
    while (cin >> word)
    {
        words.push_back(word);
    }

    // Verify words were collected

    vector_size words_collected = words.size();
    if (words_collected == 0)
    {
        cout << "You did not enter any words. Please try again." << endl;
        return 1;
    }

    vector<string> shortest_words = {words[0]};
    string_size shortest_word_length = shortest_words[0].size();

    vector<string> longest_words = {words[0]};
    string_size longest_word_length = longest_words[0].size();

    sort(words.begin(), words.end());
    for (int i = 1; i < words_collected; ++i)
    {
        const string current_word = words[i];
        const string_size current_word_length = current_word.size();

        if (current_word_length < shortest_word_length)
        {
            shortest_words = {current_word};
            shortest_word_length = current_word_length;
        }

        if (current_word_length == shortest_word_length && current_word != shortest_words[shortest_words.size() - 1])
        {
            shortest_words.push_back(current_word);
        }

        if (current_word_length > longest_word_length)
        {
            longest_words = {current_word};
            longest_word_length = current_word_length;
        }

        if (current_word_length == longest_word_length && current_word != longest_words[shortest_words.size() - 1])
        {
            longest_words.push_back(current_word);
        }
    }

    const vector_size n_shortest_words = shortest_words.size();
    if (n_shortest_words == 1)
    {
        cout << endl
             << "Shortest word (length " << shortest_word_length << "): " << shortest_words[0];
    }
    else
    {
        cout << endl
             << "Shortest word (length " << shortest_word_length << "): ";
        for (int i = 0; i < n_shortest_words; ++i)
        {
            cout << shortest_words[i];
            if (i != n_shortest_words - 1)
            {
                cout << ", ";
            }
        }
    }
    cout << endl
         << "Length: " << shortest_word_length;

    const vector_size n_longest_words = longest_words.size();
    if (n_longest_words == 1)
    {
        cout << endl
             << "Longest word (length " << longest_word_length << "): " << longest_words[0];
    }
    else
    {
        cout << endl
             << "Longest words (length " << longest_word_length << "): ";
        for (int i = 0; i < n_longest_words; ++i)
        {
            cout << longest_words[i];
            if (i != n_longest_words - 1)
            {
                cout << ", ";
            }
        }
    }
    cout << endl;

    return 0;
}
