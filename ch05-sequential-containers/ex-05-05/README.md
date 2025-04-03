# Accelerated C++

## Exercise 05.05

> Write a function named `center(const vector<string>&)` that returns a 
> picture in which all the lines of the original picture are padded out to 
> their full width, and the padding is as evenly divided as possible between 
> the left and right sides of the picture.

Implemented in `strvec.cc`

> What are the properties of pictures for which such a function is useful? How
> can you tell whether a given picture has those properties?

As noted in `center(const string&, const string_size&)`, the picture will be truly 
centered if all lines are of the same parity. If any line is of a different 
parity than the picture width, it will be shifted right by one character, 
causing the line to be off-center by one half character.
