# Accelerated C++
## Chapter 8 Exercise 5

>Reimplement the `gen_sentence` functions from Chapter 7 to use
>output iterators rather than writing their output directly to a `vector<string>`.
>Test this new version by writing programs that attach the output iterator
>directly to the standard output, and by storing the results in a
>`list<string>`and a `vector<string>`.

Writing directly to the output stream is very cool.

Additionally, in tthe benchmarking (10M iterations), I observed that lists are
just under 10% faster than vectors.

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
Directly streamed result: 
the absurd absurd table jumps on the stairs

Avg time (vector): 5970 nanoseconds
Avg time (list): 5555 nanoseconds
```
