# Accelerated C++
## Chapter 8 Exercise 2

>Implement the following library algorithms, which we used in Chapter 6 and described in
>§6.5/121. Specify what kinds of iterators they require. Try to minimize the number of distinct
>iterator operations that each function requires. After you have finished your implementation,
>see §B.3/321 to see how well you did.

- `equal(b, e, d)`
- `search(b, e, b2, e2)`
- `find(b, e, t)`
- `find_if(b, e, p)`
- `copy(b, e, d)`
- `remove_copy(b, e, d, t)`
- `remove_copy_if(b, e, d, p)`
- `remove(b, e, t)`
- `transform(b, e, d, f)`
- `partition(b, e, p)`
- `accumulate(b, e, t)`

`main.cc` output:
```
C:\projects\accelerated-cpp\build>ex-08-02
equal() test. input first vector, then "next" to input next vector. "pass" to skip.
j
o
s
h
next

Input second vector, then "end" to stop
j
o
h
n
end
0

search() test. input first vector, then "next" to input search vector. "pass" to skip.
j
o
s
h
next

Input search vector, then "end" to stop
j
o
h
n
end
j

find() test. input first vector, then "next" to input match string. "pass" to skip.
j
o
s
h
next

Input match string.
j

j

find_if() test. searching for j's. input vector, then "end" to stop. "pass" to skip.
j
o
s
h
end

Searching for j's...
found one!

copy() test. input vector, then "end" to stop. "pass" to skip.
j
o
s
h
end

destination vector:
j
o
s
h

remove_copy() test. checking for j's input vector, then "end" to stop. "pass" to skip.
j
o
s
h
j
o
s
h
end

destination vector:
o
s
h
o
s
h

remove_copy_if() test. checking for j's input vector, then "end" to stop. "pass" to skip.
j
o
s
h
j
o
s
h
end

destination vector:
o
s
h
o
s
h

remove() test. checking for j's input vector, then "end" to stop. "pass" to skip.
j
o
s
h
j
o
s
h
end

new vector:
o
s
h
o
s
h

transform() test. checking for j's. input vector, then "end" to stop. "pass" to skip.
j
o
s
h
j
o
h
n
end

destination vector:
1
0
0
0
1
0
0
0


partition() test. sorting by j's input vector, then "end" to stop. "pass" to skip.
j
o
s
h
j
o
h
n
end

partitioned vector:
j
j
s
h
o
o
h
n

accumulate() test. input vector, then "end" to stop. "pass" to skip.
j
o
s
h
!
end

Accumulated string:
josh!
```
