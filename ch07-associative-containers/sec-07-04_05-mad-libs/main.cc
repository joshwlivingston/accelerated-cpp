
#include <ctime>
#include <iostream>
#include <cstdlib>

#include "mad_libs.h"

using std::cin;
using std::cout;
using std::endl;
using std::srand;

/*
Input:
```
Categories       Rules
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
```

Output:
```
Rule Set:
<adjective>: large, brown, absurd
<location>: on the stairs, under the sky, wherever it wants
<noun-phrase>: <noun>, <adjective> <noun-phrase>
<noun>: cat, dog, table
<sentence>: the <noun-phrase> <verb> <location>
<verb>: jumps, sits

Generated sentence:
the brown cat jumps under the sky
```
*/
int main()
{
    // read input lines into grammar rule-set
    MadLibsRules mad_libs_rules;
    read(cin, mad_libs_rules);

    // display grammar rule-set
    cout << endl
         << "Rule Set:" << endl;
    for (MadLibsRules::const_iterator it = mad_libs_rules.begin(); it != mad_libs_rules.end(); ++it)
    {
        cout << it->first << ": " << *it->second.begin();
        for (rules::const_iterator rules_it = it->second.begin() + 1; rules_it != it->second.end(); ++rules_it)
        {
            cout << ", " << *rules_it;
        }
        cout << endl;
    }

    srand(time(0));
    MadLibs mad_libs = generate_mad_libs(mad_libs_rules);
    MadLibs::const_iterator it = mad_libs.begin();

    cout << endl
         << "Generated sentence:" << endl;
    if (!mad_libs.empty())
    {
        cout << *it;
        ++it;
    }

    while (it != mad_libs.end())
    {
        cout << " " << *it;
        ++it;
    }

    cout << endl;
    return 0;
}
