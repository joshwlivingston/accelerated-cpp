/*
We noted in §4.2.3/65 that it is essential that the argument types in a call to max match
exactly. Will the following code work? If there is a problem, how would you fix it?

int maxlen;
Student_info s;
max(s.name.size(), maxlen);

Ans:

The problem in the code is that maxlen is not defined when it is declared.
This means the call to max() is undefined.

To fix, I need to declare maxlen with an intial value of 0.
That way, on the first max, the maxlen will reflect the legnth of the first string tested.

int maxlen = 0;
Student_info s;
max(s.name.size(), maxlen);
*/
