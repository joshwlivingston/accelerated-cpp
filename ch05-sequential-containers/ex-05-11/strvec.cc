#include "strvec.h"

#include <stdexcept>
#include <string>

#include "charvec.h"

using std::domain_error;
using std::string;

strvec get_longest_strings(const strvec &v)
{
    if (v.size() == 0)
    {
        throw domain_error("Input must have at least one element");
    }

    strvec longest_strings = {v[0]};
    string::size_type longest_string_size = v[0].size();
    const strvec::size_type input_size = v.size();
    for (strvec::size_type i = 1; i != input_size; ++i)
    {
        const string::size_type current_word_size = v[i].size();
        if (current_word_size > longest_string_size)
        {
            longest_string_size = current_word_size;
            longest_strings = {v[i]};
        }
        else if (current_word_size == longest_string_size)
        {
            longest_strings.push_back(v[i]);
        }
    }

    return longest_strings;
}
