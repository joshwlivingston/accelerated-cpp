#ifndef GUARD_string_h
#define GUARD_string_H

#include <istream>
#include <iterator>

#include "algorithms.h"
#include "vec.h"

class String
{
public:
    typedef Vec<char>::size_type size_type;

    String() {}
    String(size_type string_size, char character)
        : data(string_size, character) {}
    String(const char *char_pointer)
    {
        copy(char_pointer, std::back_inserter(data));
    }
    template <class In>
    String(In begin, In end)
    {
        copy(begin, end, std::back_inserter(data));
    }

    char &operator[](size_type i) { return data[i]; }
    const char &operator[](size_type i) const { return data[i]; }
    String &operator+=(const String &rhs)
    {
        copy(rhs.data.begin(), rhs.data.end(), std::back_inserter(data));
        return *this;
    }

    size_type size() const { return data.size(); }
    void erase() { data.clear(); }
    void append(char in) { data.push_back(in); }

private:
    Vec<char> data;
};

// If a class supports conversions, it is a good idea to implement binary
// operators as nonmember functions

// Constructors with one argument define conversions

// `explicit` says "do not use this for conversions"

String operator+(const String &, const String &);
std::istream &operator>>(std::istream &, String &);
std::ostream &operator<<(std::ostream &, const String &);

std::back_insert_iterator<Vec<char>> copy(
    const char *char_pointer, std::back_insert_iterator<Vec<char>> dest)
{
    algo::copy<const char *, std::back_insert_iterator<Vec<char>>>(
        char_pointer, char_pointer + strlen(char_pointer), dest);
}

template <class InputIterator>
std::back_insert_iterator<Vec<char>> copy(
    InputIterator begin, InputIterator end,
    std::back_insert_iterator<Vec<char>> dest)
{
    algo::copy<InputIterator, std::back_insert_iterator<Vec<char>>>(
        begin, end, dest);
}

#endif
