#include "palindromes.h"

#include <stdexcept>
#include <string>
#include <vector>

using std::domain_error;
using std::string;
using std::vector;

vector<string> get_longest_palindromes(vector<string> &v)
{
    vector<string> longest_palindromes = {};
    string::size_type longest_palindrome_size = 0;
    for (vector<string>::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        if (!is_palindrome(*it))
        {
            continue;
        }

        const string::size_type string_size_current = it->size();
        if (string_size_current > longest_palindrome_size)
        {
            longest_palindrome_size = string_size_current;
            longest_palindromes = { *it };
        }
        else if (string_size_current == longest_palindrome_size)
        {
            longest_palindromes.push_back(*it);
        }
    }

    if (longest_palindromes.size() == 0)
    {
        throw domain_error("No palindromes found");
    }

    return longest_palindromes; 
}

vector<string> get_palindromes(vector<string> &v)
{
    vector<string> palindromes;
    for (vector<string>::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        if (is_palindrome(*it))
        {
            palindromes.push_back(*it);
        }
    }

    return palindromes;
}

bool is_palindrome(const string &s)
{
    const string::size_type n_chars = s.size();
    for (string::size_type i = 0; i != n_chars / 2; ++i)
    {
        if (s[i] != s[n_chars - 1 - i])
        {
            return false;
        }
    }

    return true;
}
