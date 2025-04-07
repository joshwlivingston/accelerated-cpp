#include "mad_libs.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>

#include "random.h"
#include "split.h"

using std::back_inserter;
using std::copy;
using std::end;
using std::find;
using std::find_if;
using std::getline;
using std::istream;
using std::list;
using std::logic_error;
using std::reverse_copy;
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
        while (char_start != rule_stack[i].end())
        {
            if (is_bracket_opener(*char_start)) // 1.
            {
                const string::iterator char_end = find_if(char_start, rule_stack[i].end(), is_space);
                if (is_bracket_closer(*(char_end - 1))) // 2.
                {
                    const MadLibsRules::const_iterator rule_list = mad_libs_rules.find(string(char_start, char_end));
                    if (rule_list != mad_libs_rules.end()) // 3.
                    {
                        /*
                        All true:
                        1. first character is <
                        2. last character in this word is >
                        3. This <word> is a MadLibs rule list entry
                        */

                        // obtain random rule from rule list
                        rule new_rule = rule_list->second[nrand(rule_list->second.size())];

                        if (char_end != rule_stack[i].end())
                        {
                            // portions of this rule have not been parsed yet

                            // preserve unparsed portion of rule in stack
                            new_rule = new_rule + string(char_end, rule_stack[i].end());
                        }

                        // append new rule to stack and begin processing it
                        rule_stack.push_back(new_rule);
                        break;
                    }
                }
            }

            // scan rule until potential new rule defintion is found
            const string::iterator char_end = find_if(char_start, rule_stack[i].end(), is_bracket_opener);

            // add everything until next rule to MadLibs output
            mad_libs.push_back(string(char_start, char_end));

            // continue scanning the rule
            char_start = char_end;
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