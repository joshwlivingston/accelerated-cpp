# Accelerated C++
## Chapter 6 Exercise 7

>The portion of the grading analysis program from §6.2.1/110 that read and classified
>student records depending on whether they did (or did not) do all the homework is similar to
>the problem we solved in `extract_fails`. Write a function to handle this subproblem.

Implemented as `extract(const vector<StudentInfo> &, bool f(const StudentInfo &))` in 
`student_info.cc` , using `stable_partition()` and `erase()`.

Using algorithms resulted in concise, performant code. It would be nice to make `extract()` a 
type-agnostic generic.
