# Accelerated C++
## Exercises 05.06

>Rewrite the extract_fails function from §5.1.1/77 so that instead of erasing
>each failing student from the input vector v, it copies the records for the 
>passing students to the beginning of v, and then uses the resize function to 
>remove the extra elements from the end of v.

Implemented in `student_info.cc`

>How does the performance of this version compare with the one in §5.1.1/77?

Due to the insertion of an element at the begining of a vector begin core to this 
rewrite, the program is considerably slower. While the original `vector` version ran
in less than half of a second, this rewrite using `insert()` and `resize()` takes over
2.5 seconds.
