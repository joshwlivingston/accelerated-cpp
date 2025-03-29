# Accelerated C++
## Chapter 5
### Section 2 - Iterators

An iterator has the following properties:
- It identifies a container and an element in the container
- It allows us to examine the value store in that element
- It provides operations for moving between elements in the container
- It restrics available operations to what the container can efficiently handle

Using an index for iteration:
```cpp
for (vector<StudentInfo>::size_type 1 = 0; i != students.size(); ++i)
{
    cout << students[i].name << endl;
}
```

Using an iterator for iteration:
```cpp
for (vector<StudentInfo>::const_iterator iter = students.begin(); iter != students.end() ++iter;)
{
    cout << (*iter).name << endl;
}
```

Every standard container, e.g. `vector`, defines two iterator types:
1. Read only access `container::const_iterator`
2. Read + Write access `container::iterator`

- `begin()` and `end()` functions return a value of the same iterator type for the container.
- `+` increments the iterator
- `*` is the dereference operator. Applied to an iterator, it returns an lvalue which is the element to which the iterator refers
- The parentheses are required in `(*iter).name` because `.` has a higher precedence than `*`.
- `(*iter).prop` can be written as `iter->prop`
