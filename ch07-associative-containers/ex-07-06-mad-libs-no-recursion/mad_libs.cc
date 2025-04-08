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
    // trigger mad libs generation using the <sentence> rule
    vector<string> rule_stack(1, "<sentence>");
    vector<string>::size_type i = 0;

    // invariant: we have processed i rules
    while (i != rule_stack.size())
    {
        // ignore leading whitespace
        string::iterator char_start = find_if(rule_stack[i].begin(), rule_stack[i].end(), is_not_space);

        // invariant: char_start marks the initial position of the portion of the rule that has yet to be parsed
        while (char_start != rule_stack[i].end() && !is_bracket_opener(*char_start))
        {
            // we are not inside a MadLibs rule tag, so we have to find the end of this string and add it to the output
            const string::iterator output_char_end = find_if(char_start, rule_stack[i].end(), is_bracket_opener);
            mad_libs.push_back(string(char_start, output_char_end));

            // continue scanning the rule
            char_start = output_char_end;
        }

        if (char_start == rule_stack[i].end())
        {
            // we have reached end of string
            ++i;
            continue;
        }

        /*
        If we are not at the end of string, then, per the while() condition, this character is a <.

        So, we should look for a MadLibs rule tag.
        */

        const string::iterator char_end = find_if(char_start, rule_stack[i].end(), is_space);
        if (!is_bracket_closer(*(char_end - 1)))
        {
            // 2. last character in this word is not >
            ++i;
            continue;
        }

        /*
        Now we know we have something that looks like a <tag>, but is it an entry in our MadLibs rules?
        */

        const MadLibsRules::const_iterator rule_list = mad_libs_rules.find(string(char_start, char_end));
        if (rule_list == mad_libs_rules.end())
        {
            // this <tag> is not a MadLibs rule entry
            ++i;
            continue;
        }

        /*
        If reach here, we have stumbled upon a MadLibs rule entry, and need to process it.

        So, we need to obtain a random rule from the list and add it to the rule stack.
        */

        const rule portion_of_rule_still_unparsed = char_end != rule_stack[i].end() ? string(char_end, rule_stack[i].end()) : "";
        const rule newly_obtained_rule = rule_list->second[nrand(rule_list->second.size())];
        rule_stack.push_back(newly_obtained_rule + portion_of_rule_still_unparsed);
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