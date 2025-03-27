/*
If the following code is legal, what can we infer about the return type of f?
double d = f()[n];

Ans:
f() returns an object, that when [] is called on it with an argument of the same type of n, 
returns a double. 

If I were to ID the return of f() based on what has been covered so far in 
the book, I could infer that f() is a function that returns a vector of doubles.
*/
