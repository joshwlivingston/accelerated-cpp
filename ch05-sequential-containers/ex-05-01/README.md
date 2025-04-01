# Accelerated C++
## Exercise 05.01

Design and implement a program to produce a permuted index. A permuted index is one in which each phrase is indexed by every word in the phrase. So, given the following input,

```
The quick brown fox
jumped over the fence
```

the output would be
```
      The quick     brown fox
jumped over the     fence
The quick brown     fox
                    jumped over the fence
         jumped     over the fence
            The     quick brown fox
    jumped over     the fence
                    The quick brown fox
```

A good algorithm is suggested in The AWK Programming Language by Aho, Kernighan, and Weinberger (Addison-Wesley, 1988). That solution divides the problem into three steps:

1. Read each line of the input and generate a set of rotations of that line. Each rotation puts the next word of the input in the first position and rotates the previous first word to the end of the phrase. So the output of this phase for the first line of our input would be:
```
The quick brown fox
quick brown fox The
brown fox The quick
fox The quick brown
```

Of course, it will be important to know where the original phrase ends and where the rotated beginning begins.

2. Sort the rotations.

3. Unrotate and write the permuted index, which involves finding the separator, putting
the phrase back together, and writing it properly formatted.

#### Note
Begininng with this section, I have switched from the `.cpp` file extension to the `.cc` file extension.
