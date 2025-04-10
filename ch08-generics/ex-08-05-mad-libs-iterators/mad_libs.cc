#include "mad_libs.h"

/*
Read string data into a grammar rule set

Input:
<noun>           cat
<noun>           dog
<noun>           table
<noun-phrase>    <noun>
<noun-phrase>    <adjective> <noun-phrase>
<adjective>      large
<adjective>      brown
<adjective>      absurd
<verb>           jumps
<verb>           sits
<location>       on the stairs
<location>       under the sky
<location>       wherever it wants
<sentence>       the <noun-phrase> <verb> <location>

Output:
<adjective>: large, brown, absurd
<location>: on the stairs, under the sky, wherever it wants
<noun-phrase>: <noun>, <adjective> <noun-phrase>
<noun>: cat, dog, table
<sentence>: the <noun-phrase> <verb> <location>
<verb>: jumps, sits
*/
void read(std::istream &in, MadLibsRules &mad_libs_rules)
{
    std::string line;
    while (std::getline(in, line))
    {
        split(line, mad_libs_rules, false);
    }
}

/*
Read a string into provided map.

The first word in string is the key.

If `separate_into_words` is true (the default), the remaining words are
appended to the vector in the map one word at a time.

If `separate_into_words` is false, the entire string (less the key) is
appended the the map's vector as one string.
*/
void split(
    const std::string &str,
    MadLibsRules &result,
    const bool separate_into_words)
{
    // ignore leading blanks
    const std::string::const_iterator start_of_key = ex0802::find_if<
        std::string::const_iterator, char>(
        str.begin(), str.end(), is_not_space);

    if (start_of_key == str.end())
        return;

    // identify first word: [char_start_key, char_end_key)
    const std::string::const_iterator end_of_key = ex0802::find_if<
        std::string::const_iterator, char>(
        start_of_key, str.end(), is_space);

    std::string::const_iterator start_of_entries = ex0802::find_if<
        std::string::const_iterator, char>(
        end_of_key, str.end(), is_not_space);
    std::back_insert_iterator<std::vector<std::string>> map_vec =
        std::back_inserter(result[std::string(start_of_key, end_of_key)]);
    if (!separate_into_words)
    {
        // populate map with rest of string, after leading whitespace
        *map_vec = std::string(start_of_entries, str.end());
        return;
    }

    // populate map one word at a time
    while (start_of_entries != str.end())
    {
        // identify next word
        std::string::const_iterator end_of_entry =
            ex0802::find_if<std::string::const_iterator, char>(
                start_of_entries, str.end(), is_space);

        // populate corresponding entry
        *map_vec++ = std::string(start_of_entries, end_of_entry);

        // continue scanning the string
        start_of_entries = ex0802::find_if<std::string::const_iterator, char>(
            end_of_entry, str.end(), is_not_space);
    }
}

void resolve_leading_rule_tags(rule &rule_stack, const MadLibsRules &rules)
{
    while (
        rule_stack.begin() != rule_stack.end()
        && is_bracket_open(*rule_stack.begin()))
    {
        // locate end of current word
        const rule::iterator rule_tag_ending_space =
            ex0802::find_if<rule::iterator, char>(
                rule_stack.begin(), rule_stack.end(), is_space);

        // if word does not end with <, it is not a rule tag
        if (!is_bracket_close(*(rule_tag_ending_space - 1)))
            break;

        // locate rule tag from provided rules
        const MadLibsRules::const_iterator rule_list =
            rules.find(std::string(rule_stack.begin(), rule_tag_ending_space));

        // if tag not found in rule list, it is not a rule tag
        if (rule_list == rules.end())
            break;

        rule_stack =
            // choose a rule from provided rules at random
            rule_list->second[nrand(rule_list->second.size())]
            // append unparsed portion of rule_stack to newly chosen rule
            + std::string(rule_tag_ending_space, rule_stack.end());
    }
}

/* Finds the start of the next potential rule tag. Ignores the first '<' found
   if string starts with '<'. Do not use this function to process rule tags.
   Instead, use resolve_leading_rule_tags(). */
rule::iterator get_next_start(rule::iterator begin, const rule::iterator end)
{
    if (is_bracket_open(*begin))
        ++begin;
    return ex0802::find_if<rule::iterator, char>(begin, end, is_bracket_open);
}
