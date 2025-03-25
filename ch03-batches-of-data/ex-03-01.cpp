/*
Suppose we wish to find the median of a collection of values. Assume that we have read
some of the values so far, and that we have no idea how many values remain to be read.
Prove that we cannot afford to discard any of the values that we have read. Hint: One proof
strategy is to assume that we can discard a value, and then find values for the unread—and
therefore unknown—part of our collection that would cause the median to be the value that we
discarded.

Ans:

Suppose we have read three grades so far: 80, 82, and 85.

Now, let us discard 85. And suppose we read in two more values: 87 and 90.

The median of the result is 84.5; however, had the 85 not been discarded, the median would have been 85.

The same pattern can be applied to the other two values, showing they cannot be removed.alignas

By induction, this extends to any number of so-far-read values.
*/
