#ifndef GUARD_iterator_h
#define GUARD_iterator_h

template <class T>
class Iterator
{
public:
    Iterator() { set_pointers_to_zero(); }
    Iterator(T &val) { assign(val); }
    ~Iterator() { set_pointers_to_zero(); }
    Iterator &operator++() const { return *next_; }
    const T &operator*() const{ return dereference(); }

protected:
    typedef T *address;

    void set_pointers_to_zero() {
        data = 0;
        next_ = 0;
    }

    void assign(T &val) { data = &val; }

    void assign(T &val, Iterator &next) {
        data = &val;
        next_ = &next;
    }

    bool is_equal(const Iterator &rhs) const { return this == &rhs; }

    T &dereference() const { return *data; }

    address data;
    Iterator<T> *next_ = 0;
};

#endif // GUARD_iterator_h