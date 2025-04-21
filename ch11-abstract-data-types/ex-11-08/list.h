#ifndef GUARD_list_h
#define GUARD_list_h

#include <cstddef>

template <class T>
class ListNode
{
public:
    ListNode() {}
    ListNode(const T &val) { data = val; }
    ListNode(const ListNode &prev_node, const T &val)
    {
        data = val;
        prev = &prev_node;
    }
    ListNode(const T &val, const ListNode &next_node)
    {
        data = val;
        next = &next_node;
    }
    ListNode(const ListNode &prev_node, const T &val,
             const ListNode &next_node)
    {
        data = val;
        next = &next_node;
        prev = &prev_node;
    }

    T data;
    ListNode *next;
    ListNode *prev;
};

template <class T>
class ListNodeIterator
{
public:
    ListNodeIterator() : current(new ListNode<T>()) {}
    ListNodeIterator(ListNode<T> &node) { current = &node; }

    ListNodeIterator &operator++()
    {
        current = current->next;
        return *this;
    }
    ListNodeIterator &operator--()
    {
        current = current->prev;
        return *this;
    }
    T &operator*() { return current->data; }
    bool operator==(const ListNodeIterator &rhs) const { return current == rhs.current; }
    bool operator!=(const ListNodeIterator &rhs) const { return current != rhs.current; }
    void update_next_ref(ListNodeIterator &new_next) { current->next = new_next.current; }
    void update_prev_ref(ListNodeIterator &new_prev) { current->prev = new_prev.current; }
    void remove_next_ref() { current->next = new ListNode<T>(); }
    void remove_prev_ref() { current->prev = new ListNode<T>(); }

    ListNode<T> *current;
};

template <class T>
class List
{
public:
    typedef ListNodeIterator<T> iterator;
    typedef const ListNodeIterator<T> const_iterator;
    typedef std::size_t size_type;
    typedef T value_type;

    List()
    {
        data = new iterator();
        last = avail = new iterator();
        data->update_next_ref(*last);
        last->update_prev_ref(*data);
    }

    List(const T &val)
    {
        ListNode<T> *node = new ListNode<T>(val);
        data = new iterator(*node);
        last = avail = new iterator();
        data->update_next_ref(*last);
        last->update_prev_ref(*data);
        size_ = 1;
    }
    List(const size_type &n, const T &val)
    {
        if (n == 0)
            return;

        ListNode<T> *node = new ListNode<T>(val);
        data = new iterator(*node);
        ++size_;
        if (n == 1) return;

        iterator *current = data;
        while (true)
        {
            ListNode<T> *node = new ListNode<T>(val);
            iterator *new_it = new iterator(*node);
            current->update_next_ref(*new_it);
            new_it->update_prev_ref(*current);
            ++size_;
            if (size_ == n) {
                last = avail = new iterator();
                new_it->update_next_ref(*last);
                last->update_prev_ref(*new_it);
                break;
            }
            current = new_it;
        }
    }

    ~List() {uncreate();}
    
    void clear() {uncreate();}
    const_iterator &begin() { return *data; }
    const_iterator &end() { return *last; }
    size_type size() { return size_; }

private:
    void uncreate()
    {
        iterator *current = data;
        while (current != nullptr)
        {
            iterator *next = &++*current;
            delete current;
            if (next == avail)
                break;
            current = next;
        }
        delete avail;
    }

    iterator *data;
    iterator *last;
    iterator *avail;
    size_type size_ = 0;
};

#endif
