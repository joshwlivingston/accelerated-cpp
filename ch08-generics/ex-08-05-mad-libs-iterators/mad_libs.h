#ifndef GUARD_mad_libs_h
#define GUARD_mad_libs_h

#include <istream>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>

#include "algorithms.h"
#include "random.h"
#include "utils.h"

typedef std::string rule;
typedef std::vector<rule> rules;
typedef std::map<std::string, rules> MadLibsRules;

void read(std::istream &, MadLibsRules &);
void split(const std::string &, MadLibsRules &, const bool);

void resolve_leading_rule_tags(rule &, const MadLibsRules &);
rule::iterator get_next_start(const rule::iterator, const rule::iterator);

/* Generates a Mad-Libs style sentence using provided MadLibs ruleset.
   A <sentence> rule must be defined in the rule-set for the generator to
   work. */
template <class OutputIterator>
OutputIterator generate_mad_libs(
    OutputIterator destination,
    const MadLibsRules &rules)
{
    rule rule_stack = "<sentence>";
    while (rule_stack.begin() != rule_stack.end())
    {
        resolve_leading_rule_tags(rule_stack, rules);
        const rule::iterator next_start =
            get_next_start(rule_stack.begin(), rule_stack.end());
        *destination++ = std::string(rule_stack.begin(), next_start);
        rule_stack = std::string(next_start, rule_stack.end());
    }
    return destination;
}

#endif
