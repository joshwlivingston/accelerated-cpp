# Accelerated C++
## Chapter 7 Exercise 2

### Exercise Text
Extend the program in §4.2.3/64 to assign letter grades by ranges:
```
A 90-100
B 80-89.99...
C 70-79.99...
D 60-69.99...
F < 60
```

The output should list how many students fall into each category.

### Answer
The letter grade calculation is implemented in `grace.cc`, and the output
is a map implemented in `student_info.cc`:
```cpp
void get_letter_grades(const Students &students, CountsByLetterGrade &result)
{
    ...
}
```
