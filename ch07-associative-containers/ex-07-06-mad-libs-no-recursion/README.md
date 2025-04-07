# Accelerated C++
## Chapter 7 Exercise 6

>Reimplement the gen_sentence program using two vectors: One will hold the fully
>unwound, generated sentence, and the other will hold the rules and will be used as a stack.
>Do not use any recursive calls.

This was a wonderful exercise. The final implementation scans the rules as they are provided,
stopping to resolve any rules before proceeding through the remainder of the rule. This results
in an O(n) implementaiton, where n is the number of characters in the original rule + the 
characters added rules due added rules + the characters in the output.

One fallback is this this function could theoretically continue forever. The <noun-phrase> rule
is self-referential, meaning this implementation could continue to add <noun-phrase> rules to the
stack. Another is the general lack of error catching, especially on the rule set creation.

Rules stack in final implementation:
```
Step 00: Start the generation with the <sentence> rule

Step 0: Add sentence rule to stack
[t0] = "<sentence>"

Step 1: Add "the" to MadLibs data. Obtain <noun-phrase>.
[t1] = "the <noun-phrase> <verb> <location>"

Step 2: Obtain <adjective> rule
[t2] = "<adjective> <noun-phrase> <verb> <location>"

Step 3: Add "large" to MadLibs. Obtain <noun-phrase> rule
[t3] = "large <noun-phrase> <verb> <location>"

Step 4: Obtain <adjective> rule
[t4] = "<adjective> <noun-phrase> <verb> <location>"

Step 5: Add "brown" to MadLibs. Obtain <noun-phrase> rule.
[t5] = "brown <noun-phrase> <verb> <location>"

Step 6: Obtain <noun> rule
[t6] = "<noun> <verb> <location>"

Step 7: Add "dog" to MadLibs. Obtain <verb> rule.
[t7] = "dog <verb> <location>>"

Step 8: Add "sits" to MadLibs. Obtain <location> rule.
[t8] = "sits <location>"

Step 9: Add "wherever it wants" to MadLibs.
[t9] = "wherever it wants"
```

Output:
```
[0] = "the" 
[1] = "large"
[3] = "brown"
[4] = "dog"
[5] = "sits"
[6] = "wherever it wants"
```
