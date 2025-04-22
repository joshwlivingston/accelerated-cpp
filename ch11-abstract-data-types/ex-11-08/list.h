#ifndef GUARD_list_h
#define GUARD_list_h

#include <cstddef>

template <class T>
class ListNode
{
public:
    ListNode() : data(nullptr), next(nullptr), prev(nullptr) {}
    ListNode(const T &val) : data(new T(val)), next(nullptr), prev(nullptr) {}
    ListNode(const ListNode &prev_node, const T &val) : data(new T(val)),
                                                        next(nullptr),
                                                        prev(&prev_node) {}
    ListNode(const T &val, const ListNode &next_node) : data(new T(val)),
                                                        next(&next_node),
                                                        prev(nullptr) {}
    ListNode(const ListNode &prev_node, const T &val,
             const ListNode &next_node) : data(new T(val)), next(&next_node),
                                          prev(prev_node) {}

    ~ListNode() { delete data; }

    T *data;
    ListNode *next;
    ListNode *prev;
};

template <class T>
class ListNodeIterator
{
public:
    ListNodeIterator() : current(new ListNode<T>()) {}
    ListNodeIterator(ListNode<T> &node) { current = &node; }

    ~ListNodeIterator() {}

    ListNodeIterator operator++()
    {
        current = current->next;
        return *this;
    }
    ListNodeIterator operator++(int)
    {
        ListNodeIterator res = *this;
        ++(*this);
        return res;
    }
    ListNodeIterator operator--()
    {
        current = current->prev;
        return *this;
    }
    ListNodeIterator operator--(int)
    {
        ListNodeIterator res = *this;
        --(*this);
        return res;
    }
    T &operator*() { return *current->data; }
    bool operator==(const ListNodeIterator &rhs) const
    {
        return current == rhs.current;
    }
    bool operator!=(const ListNodeIterator &rhs) const
    {
        return current != rhs.current;
    }
    void update_next_ref(ListNodeIterator &new_next)
    {
        current->next = new_next.current;
    }
    void update_prev_ref(ListNodeIterator &new_prev)
    {
        current->prev = new_prev.current;
    }
    void remove_next_ref() { current->next = nullptr; }
    void remove_prev_ref() { current->prev = nullptr; }

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
        last->update_next_ref(*avail);
    }

    List(const T &val)
    {
        ListNode<T> *node = new ListNode<T>(val);
        data = new iterator(*node);
        last = avail = new iterator();
        data->update_next_ref(*last);
        last->update_prev_ref(*data);
        last->update_next_ref(*avail);
        size_ = 1;
    }
    List(const size_type &n, const T &val)
    {
        if (n == 0)
            return;

        ListNode<T> *node = new ListNode<T>(val);
        data = new iterator(*node);
        ++size_;
        if (n == 1)
            return;

        iterator *current = data;
        while (true)
        {
            ListNode<T> *node = new ListNode<T>(val);
            iterator *new_it = new iterator(*node);
            current->update_next_ref(*new_it);
            new_it->update_prev_ref(*current);
            ++size_;
            if (size_ == n)
            {
                last = avail = new iterator();
                new_it->update_next_ref(*last);
                last->update_prev_ref(*new_it);
                last->update_next_ref(*avail);
                break;
            }
            current = new_it;
        }
    }

    ~List() { uncreate(); }

    void insert(iterator &where, iterator &insert_begin, iterator &insert_end)
    {
        insert(where, insert_begin, insert_end,
               length(insert_begin, insert_end));
    }
    void insert(iterator &where, iterator &insert_begin, iterator &insert_end,
                size_type n_inserted)
    {
        iterator one_after_where = where;
        ++one_after_where;
        where.update_next_ref(insert_begin);
        insert_begin.update_prev_ref(where);
        iterator last_element_inserted = insert_end;
        --last_element_inserted;
        last_element_inserted.update_next_ref(one_after_where);
        one_after_where.update_prev_ref(last_element_inserted);
        size_ += n_inserted;
    }
    void erase(iterator &erase_begin, iterator &erase_end)
    {
        if (erase_begin == erase_end)
            return;

        const size_type n_erased = length(erase_begin, erase_end);

        if (&erase_end == &end())
        {
            if (last == avail)
                avail = &erase_end;
            last = &erase_begin;
        }

        else
        {
            remove_link(erase_begin, erase_end);
        }

        size_ -= n_erased;
    }
    void resize() { remove_erased_elements(); }
    void clear() { uncreate(); }

    iterator &begin() { return *data; }
    iterator &end() { return *last; }
    size_type size() { return size_; }

private:
    void remove_erased_elements()
    {
        iterator current = *last;
        if (last != avail)
            ++current;
        while (current != *avail)
        {
            delete current.current->data;
            ++current;
        }
    }
    void uncreate()
    {
        iterator current = *data;
        while (current != *avail)
        {
            delete current.current->data;
            ++current;
        }
    }
    void remove_link(iterator &erase_begin, iterator &erase_end)
    {
        iterator link_before_end = erase_end;
        --link_before_end;
        if (erase_begin == begin())
        {
            data = &erase_end;
            iterator link_before_last = *avail;
            --link_before_last;
            link_before_last.update_next_ref(erase_begin);
            erase_begin.update_prev_ref(link_before_last);
            if (last == avail)
                last = &erase_begin;
            avail = &link_before_end;
        }
        else
        {
            iterator link_before_begin = erase_begin;
            --link_before_begin;
            link_before_begin.update_next_ref(erase_end);
            erase_end.update_prev_ref(link_before_begin);

            link_before_end.update_next_ref(erase_begin);

            avail->update_next_ref(erase_begin);
            erase_begin.update_prev_ref(*avail);
            link_before_end.remove_next_ref();
            avail = &link_before_end;
        }
    }

    size_type length(iterator &begin, const_iterator &end) const
    {
        iterator current = begin;
        size_type out = 0;
        while (current != end)
        {
            ++out;
            ++current;
        }
        return out;
    }

    iterator *data;
    iterator *last;
    iterator *avail;
    size_type size_ = 0;
};

#endif
