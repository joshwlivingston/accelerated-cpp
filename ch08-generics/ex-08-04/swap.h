#ifndef GUARD_swap_h
#define GUARD_swap_h

namespace ex0804 {

template<class T> void swap(T &x, T &y)
{
    const T z = x;
    x = y;
    y = z;
}

} // namespace ex0804

#endif
