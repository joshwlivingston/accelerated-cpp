#include "mad_libs.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "random.h"
#include "split.h"

using std::find_if;
using std::getline;
using std::istream;
using std::string;
using std::vector;

/*
Generates a Mad-Libs style sentence using provided MadLibs ruleset.
A <sentence> rule must be defined in the rule-set for the generator to work.
*/
MadLibs generate_mad_libs(const MadLibsRules &mad_libs_rules)
{
    MadLibs mad_libs;
    vector<string> rule_stack(1, "<sentence>");
    vector<string>::size_type i = 0;
    while (i != rule_stack.size())
    {
        string::iterator char_start = find_if(rule_stack[i].begin(), rule_stack[i].end(), is_not_space);
        while (char_start != rule_stack[i].end())
        {
            if (is_bracket_opener(*char_start))
            {
                const string::iterator rule_tag_ending_space = find_if(char_start, rule_stack[i].end(), is_space);
                if (is_bracket_closer(*(rule_tag_ending_space - 1)))
                {
                    const MadLibsRules::const_iterator rule_list = mad_libs_rules.find(string(char_start, rule_tag_ending_space));
                    if (rule_list != mad_libs_rules.end())
                    {
                        /*
                        If reach here, we have stumbled upon a MadLibs rule entry, and need to process it.
                        So, we need to obtain a random rule from the list and add it to the rule stack.
                        */
                        const rule newly_obtained_rule = rule_list->second[nrand(rule_list->second.size())];
                        const rule portion_of_rule_still_unparsed = rule_tag_ending_space == rule_stack[i].end() ? "" : string(rule_tag_ending_space + 1, rule_stack[i].end());
                        rule_stack.push_back(newly_obtained_rule + " " + portion_of_rule_still_unparsed);
                        break;
                    }
                }
            }
            /*
            The beginning of the string is not a valid rule tag.
            So, add portion of string until we find a rule tag to MadLibs output
            */
            string::iterator next_potential_rule_start = find_if(char_start, rule_stack[i].end(), is_bracket_opener);
            while (char_start == next_potential_rule_start || (!is_space(*(next_potential_rule_start - 1)) && next_potential_rule_start != rule_stack[i].end()))
            {
                /*
                char_start is < but we are not in a tag, OR we have found a <, but the preceding character is not a space and we are not at the end
                So, we should continue scanning for another valid <
                */
                next_potential_rule_start = find_if(next_potential_rule_start + 1, rule_stack[i].end(), is_bracket_opener);
            }
            mad_libs.push_back(string(char_start, next_potential_rule_start));
            char_start = next_potential_rule_start;
        }
        ++i;
    }
    return mad_libs;
}

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
void read(istream &in, MadLibsRules &mad_libs_rules)
{
    string line;
    while (getline(in, line))
    {
        split(line, mad_libs_rules, false);
    }
}

bool is_bracket_opener(char c)
{
    return c == '<';
}

bool is_bracket_closer(char c)
{
    return c == '>';
}

bool is_bracketed(const string &s)
{
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}