#include "strings.h"
#include "stringvec.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

/*
Generate a set of rotations for a string.

Each rotation puts the next word of the input in the first position and rotates the
previous first word to the end of the phrase.

So the output of the phase "The quick brown fox" would be:

```
The quick brown fox
quick brown fox The
brown fox The quick
fox The quick brown
```
*/
vector<string> get_rotations(const string &s)
{
    const vector<string> words = split(s);
    const stringvec_size n_words = words.size();
    vector<string> rotations;

    for (stringvec_size i = 0; i != n_words; ++i)
    {
        // current index through end of word
        string rotation = words[i];
        for (stringvec_size j = i + 1; j != n_words; ++j)
        {
            rotation = rotation + " " + words[j];
        }

        // words from beginning of original, rotated to end
        for (stringvec_size k = 0; k != i; ++k)
        {
            rotation = rotation + " " + words[k];
        }

        rotations.push_back(rotation);
    }

    return rotations;
}

// Returns the first word in a string, or "" if the string is entirely whitespace
string get_first_word(const string &s)
{
    const string_size s_size = s.size();
    // get first non whitespace index
    string_size i = 0;
    while (i != s_size)
    {
        if (!isspace(s[i]))
        {
            break;
        }
        ++i;
    }

    // get next whitespace index
    string_size j = i;
    while (j != s_size)
    {
        if (isspace(s[j]))
        {
            break;
        }
        ++j;
    }

    // first word are the characters at [i, j)
    string first_word = "";
    if (i != s_size)
    {
        first_word = s.substr(i, j - i);
    }
    
    return first_word;
}

// Splits a string into words separated by whitespace
vector<string> split(const string &s)
{
    vector<string> words;
    const string_size s_length = s.size();
    string_size i = 0;

    while (i != s_length)
    {
        // ignore leading blanks
        while (i != s_length && isspace(s[i]))
        {
            ++i;
        }

        // Do any non-whitespace characters exist?
        string_size j = i;
        while (j != s_length && !isspace(s[j]))
        {
            ++j;
        }

        if (i != j)
        {
            words.push_back(s.substr(i, j - i));
            i = j;
        }
    }

    return words;
}
