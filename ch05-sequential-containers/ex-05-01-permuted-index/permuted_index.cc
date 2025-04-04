/*
# Accelerated C++
## Exercise 05.01

Design and implement a program to produce a permuted index. A permuted index is one in which each phrase
is indexed by every word in the phrase. So, given the following input,

```
The quick brown fox
jumped over the fence
```

the output would be
```
      The quick     brown fox
jumped over the     fence
The quick brown     fox
                    jumped over the fence
         jumped     over the fence
            The     quick brown fox
    jumped over     the fence
                    The quick brown fox
```
*/

#include "permuted_index.h"
#include "strings.h"
#include "stringvec.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::getline;
using std::max;
using std::sort;
using std::string;
using std::vector;

/*

Returns a permuted index for a vector of strings. A permuted index is one in which each phrase
is indexed by every word in the phrase.
*/
PermutedIndex get_permuted_index(const vector<string> &v)
{
    PermutedIndex permuted_index;
    for (const_iter_strvec provided_string = v.begin(); provided_string != v.end(); ++provided_string)
    {
        /*
        1. Read each line of the input and generate a set of rotations of that line.
        */
        const string first_word = get_first_word(*provided_string);
        const vector<string> rotations = get_rotations(*provided_string);
        const const_iter_strvec rotation_first = rotations.begin();

        for (const_iter_strvec rotation = rotation_first; rotation != rotations.end(); ++rotation)
        {
            /*
            2. For each rotation, separate all words as "word" or "index" based
               on if word is before or after the originally first word in the string
            */
            const vector<string> rotation_words_split = split(*rotation);

            const const_iter_strvec rotation_word_first = rotation_words_split.begin();

            if (*rotation_word_first == first_word)
            {
                PermutedIndexEntry permuted_index_entry;
                permuted_index_entry.word_list = rotation_words_split;
                permuted_index.index_entries.push_back(permuted_index_entry);
                permuted_index.max_index_width = max(permuted_index.max_index_width, width(rotation_words_split));
            }
            else
            {
                const_iter_strvec rotation_word = rotation_word_first;

                const const_iter_strvec rotation_word_last = rotation_words_split.end();

                PermutedIndexEntry permuted_index_entry;
                while (rotation_word != rotation_word_last && *rotation_word != first_word)
                {
                    // if the rotation's word is before the original first word in the string, it is a word in the index entry
                    permuted_index_entry.word_list.push_back(*rotation_word);
                    ++rotation_word;
                }

                // if this rotation has words
                if (*rotation_word != *rotation_word_first)
                {
                    while (rotation_word != rotation_word_last)
                    {
                        // if the rotation's word is not before the original first word in the string, it is a word in the index entry
                        permuted_index_entry.index_list.push_back(*rotation_word);
                        ++rotation_word;
                    }

                    permuted_index.index_entries.push_back(permuted_index_entry);
                    permuted_index.max_index_width = max(permuted_index.max_index_width, width(permuted_index_entry.index_list));
                }
            }
        }
    }

    sort(permuted_index.index_entries.begin(), permuted_index.index_entries.end(), compare);

    return permuted_index;
}

// Does the x's word list's first elemenet precede y's?
bool compare(const PermutedIndexEntry &x, const PermutedIndexEntry &y)
{
    return x.word_list[0] < y.word_list[0];
}

std::vector<std::string> hcat(PermutedIndex &p, const string &delim)
{
    vector<string> indexes_all;
    vector<string> words_all;
    for (vector<PermutedIndexEntry>::size_type i = 0; i != p.index_entries.size(); ++i)
    {
        p.index_entries[i].index_list.push_back(delim);
        indexes_all.push_back(hcat(p.index_entries[i].index_list));
        words_all.push_back(hcat(p.index_entries[i].word_list));
    }

    return hcat(indexes_all, words_all, true, false);
}

int main()
{
    const string kOutputDelim = "|";

    vector<string> inputs_collected;
    string input;
    while (getline(cin, input))
    {
        inputs_collected.push_back(input);
    }

    PermutedIndex permuted_index = get_permuted_index(inputs_collected);
    const vector<string> display_rows = hcat(permuted_index, kOutputDelim);
    for (const_iter_strvec it = display_rows.begin(); it != display_rows.end(); ++it)
    {
        cout << *it << endl;
    }

    return 0;
}
