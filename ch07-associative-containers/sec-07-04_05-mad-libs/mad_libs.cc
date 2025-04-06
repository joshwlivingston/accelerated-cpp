#include "mad_libs.h"

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "random.h"
#include "split.h"

using std::getline;
using std::istream;
using std::logic_error;
using std::string;
using std::vector;

MadLibs generate_mad_libs(const MadLibsRules &mad_libs_rules)
{
    MadLibs mad_libs;
    r_generate_mad_libs(mad_libs_rules, "<sentence>", mad_libs);
    return mad_libs;
}

void r_generate_mad_libs(const MadLibsRules &mad_libs_rules, const string &word, MadLibs &mad_libs)
{
    if (!is_bracketed(word))
    {
        mad_libs.push_back(word);
    }
    else
    {
        MadLibsRules::const_iterator it = mad_libs_rules.find(word);
        if (it == mad_libs_rules.end())
        {
            throw logic_error("Empty rule");
        }

        const rules rules = it->second;
        const rule rule_selected = rules[nrand(rules.size())];

        vector<string> rule_words;
        split(rule_selected, rule_words);
        for (vector<string>::const_iterator word = rule_words.begin(); word != rule_words.end(); ++word)
        {
            r_generate_mad_libs(mad_libs_rules, *word, mad_libs);
        }
    }
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

bool is_bracketed(const string &s)
{
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}