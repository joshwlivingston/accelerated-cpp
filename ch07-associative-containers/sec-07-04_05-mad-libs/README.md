# Accelerated C++
## Chapter 7 Section 4 - Mad Libs

Our goal is to create a randomized "mad-libs" style program that generates
sentences using the following rules:

Input:
```
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
the brown cat jumps under the sky
```

### Implementation

#### read()
In `mad_libs.h`, we declare `read(istream &, MadLibsRules &);`, which reads an input stream 
into the rule format shown above. We define that rule format as a `typedef` -  
`map<string, vector<string>>` - name it `MadLibsRules`.

Differing from the book's use of `split(const string &)`, the functionality here is
mostly implemented in `split.cc`:
```cpp
// split.cc
void split(
    const std::string &str,
    std::map<std::string, std::vector<std::string>> &result,
    const bool separate_into_words)
{
    ...
}
```
and declared in `"split.h"`. This function splits an input string into a key-value pair,
and adds that key-value pair to the input map. With this implementation of `split()`, 
we can parse the input string and construct the map in one step. The book 
implementation requires two steps.
