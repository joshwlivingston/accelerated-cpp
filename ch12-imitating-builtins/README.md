# Accelerated C++
## Chapter 12: Making class objects act like values

Class authors control the extent to which classes behave like built-in values.
This contorl comes from the implementation of conventional operators,
behaviors, etc.

The `string` is an object that behaves "like a value." The code in this chapter
will implement a simplified version of `string`, `String`.

Most of the functionality was covered in chapter 11, when building the `vec`
class. This chapter will focus more on the design of the interface.
