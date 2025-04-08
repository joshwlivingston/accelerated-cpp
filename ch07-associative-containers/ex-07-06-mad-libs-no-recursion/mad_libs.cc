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
            if (!is_bracket_opener(*char_start))
            {
                /*
                We are not inside a MadLibs rule tag.
                So, we should find the end of this string and add it to the output.
                The end of this string is marked by the position of the next '<' in the rule.
                */
                const string::iterator char_end = find_if(char_start, rule_stack[i].end(), is_bracket_opener);
                mad_libs.push_back(string(char_start, char_end));
                char_start = char_end;
                continue;
            }
            /*
            If we are here, then this character is a '<'.
            So, we should look for a MadLibs rule tag.
            */
            const string::iterator char_end = find_if(char_start, rule_stack[i].end(), is_space);
            const MadLibsRules::const_iterator rule_list = mad_libs_rules.find(string(char_start, char_end));
            if (!is_bracket_closer(*(char_end - 1)) || rule_list == mad_libs_rules.end())
            {
                /*
                Last character in this word is not '>' OR this <tag> is not a valid MadLibs rule entry.
                So, we should add this portion of the rule to the mad_libs output and continue scanning the string.
                */
                mad_libs.push_back(string(char_start, char_end));
                char_start = char_end;
                continue;
            }
            /*
            If reach here, we have stumbled upon a MadLibs rule entry, and need to process it.
            So, we need to obtain a random rule from the list and add it to the rule stack.
            */
            const rule newly_obtained_rule = rule_list->second[nrand(rule_list->second.size())];
            const rule portion_of_rule_still_unparsed = char_end == rule_stack[i].end() ? "" : string(char_end, rule_stack[i].end());
            rule_stack.push_back(newly_obtained_rule + portion_of_rule_still_unparsed);
            break;
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