/*
Why 
  `for (int i = 0; i != i_total; ++i) {}` 
and not 
  `for (int i = 1; i <= i_total; ++i) {}` 
?

1. We can use asymmetric range to describe  ( [0, rows) vs [1, rows] )
    - Asymmetric range has nice property:
        - [m, n) has n - m elements
            - so, n of [0, rows] is obvious
        - [m, n] has n - m + 1 elements
            - n of [1, rows] is less obvious

2. Easier to write invariant when starting at 0
    - "We have written i rows" vs "We have written i - 1 rows"

3. Using != instead of <= allows for direct proof of what was written
    - At the end, we know i == rows
*/
int main() {}
