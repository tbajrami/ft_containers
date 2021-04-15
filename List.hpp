/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbajrami <tbajrami@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 12:22:38 by tbajrami          #+#    #+#             */
/*   Updated: 2021/04/15 11:55:57 by tbajrami         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <iterator>
#include "BidirectionalIterator.hpp"
#include "Node.hpp"

namespace ft
{

template <class T>
class List
{
public:

    typedef T value_type;
    typedef size_t size_type;
    typedef ft::BIterator<T> iterator;
    typedef ft::BReverseIterator<T> reverse_iterator;
    typedef ft::BConstIterator<T> const_iterator;
    typedef ft::BReverseConstIterator<T> const_reverse_iterator;

private:

    Node<value_type>      *_node_begin;
    Node<value_type>      *_node_end;
    size_type             _size;

public:

    explicit List() : _size(0) {init_list();}

    explicit List(size_type n, const value_type &val = value_type())
    {
        init_list();
        for (size_t i = 0 ; i < n ; i++)
            push_back(val);
    }

    List(const List &x)
    {
        input_dispatch(x.begin(), x.end());
    }

    template <class InputIterator>
    List (InputIterator first, InputIterator last) : _size(0)
    {
        input_dispatch(first, last);
    }

    ~List() {this->del_list();}

    List &operator=(const List &x)
    {
        this->del_list();
        input_dispatch(x.begin(), x.end());
        return *this;
    }

    /* ITERATORS */

    iterator begin()
    {
        iterator it;
        it.setPtr(_node_begin);
        return it;
    }

    const_iterator begin() const
    {
        const_iterator it;
        it.setPtr(_node_begin);
        return it;
    }

    iterator end()
    {
        iterator it;
        if (_size)
            it.setPtr(_node_end);
        else
            it.setPtr(_node_begin);
        return it;
    }

    const_iterator end() const
    {
        const_iterator it;
        if (_size)
            it.setPtr(_node_end);
        else
            it.setPtr(_node_begin);
        return it;
    }

    reverse_iterator rbegin()
    {
        reverse_iterator it;
        if (_size != 0)
            it.setPtr(_node_end->prev);
        else
            it.setPtr(_node_begin);
        return it;
    }

    const_reverse_iterator rbegin() const
    {
        const_reverse_iterator it;
        if (_size != 0)
            it.setPtr(_node_end->prev);
        else
            it.setPtr(_node_begin);
        return it;
    }

    reverse_iterator rend()
    {
        reverse_iterator it;
        if (_size != 0)
            it.setPtr(_node_begin->prev);
        else
            it.setPtr(_node_begin);
        return it;
    }

    const_iterator rend() const
    {
        const_reverse_iterator it;
        if (_size != 0)
            it.setPtr(_node_begin->prev);
        else
            it.setPtr(_node_begin);
        return it;
    }

    /* CAPACITY */

    bool empty() const {return (_size == 0);}
    size_type size() const {return _size;}
    size_type max_size() const {return std::numeric_limits<size_type>::max() / sizeof(Node<value_type>);}

    /* ELEMENT ACCESS */

    value_type &front() {return _node_begin->elem;}
    const value_type &front() const {return _node_begin->elem;}

    value_type &back() {return _node_end->prev->elem;}
    const value_type &back() const {return _node_end->prev->elem;}

    /* MODIFIERS */

    void push_front(const value_type &val)
    {
        if (_size == 0)
            push_back(val);
        else
        {
            Node<value_type> *n = new Node<value_type>;
            _node_begin->prev->elem = val;
            _node_begin->prev->next = _node_begin;
            _node_begin->prev->prev = n;
            _node_begin = _node_begin->prev;
        }
        _size += 1;
    }

    void pop_front()
    {
        if (_size > 1)
        {
            delete _node_begin->prev;
            _node_begin = _node_begin->next;
            _size -= 1;
        }
        else if (_size == 1)
        {
            delete _node_begin->prev;
            _size -= 1;
        }
    }

    void push_back(const value_type &val)
    {

        if (_size == 0)
        {
            _node_begin->elem = val;
            _node_begin->prev = new Node<value_type>;
            _node_begin->prev->next = _node_begin;
            _node_end->prev = _node_begin;
        }
        else
        {
            Node<value_type> *n = new Node<value_type>;
            _node_end->elem = val;
            _node_end->next = n;
            n->prev = _node_end;
            _node_end = n;
        }
        _size += 1;
    }

    void pop_back()
    {
        if (_size > 1)
        {
            _node_end = _node_end->prev;
            delete _node_end->next;
            _node_end->next = NULL;
            _size -= 1;
        }
        else if (_size == 1)
        {
            delete _node_begin->prev;
            _size -= 1;
        }
    }

    void assign(size_type n, const value_type &val)
    {
        this->del_list();
        input_dispatch(n, val);
    }

    template <class InputIterator>
    void assign(InputIterator first, InputIterator last)
    {
        this->del_list();
        input_dispatch(first, last);
    }

    iterator insert(iterator position, const value_type &val)
    {
        Node<value_type> *nn = new Node<value_type>;
        Node<value_type> *temp = _node_begin;

        if (!_size && position == begin())
        {
            push_back(val);
            return begin();
        }
        for (ft::List<value_type>::iterator it = this->begin() ; it != position ; it++)
            temp = temp->next;
        nn->elem = val;
        nn->prev = temp->prev;
        nn->next = temp;
        temp->prev->next = nn;
        temp->prev = nn;
        _size += 1;
        return position;
    }

    void insert(iterator position, size_type n, const value_type &val)
    {
        for (size_type i = 0 ; i < n ; i++)
            this->insert(position, val);
    }

    template <class InputIterator>
    void insert(iterator position, InputIterator first, InputIterator last)
    {
        insert_dispatch(position, first, last);
    }

    iterator erase(iterator position)
    {
        Node<value_type> *temp = _node_begin;

        if (position == begin())
        {
            pop_front();
            position = begin();
        }
        else if (_size >= 1)
        {
            for (iterator it = this->begin() ; it != position ; it++)
                temp = temp->next;
            position++;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            if (_size > 1)
                delete temp;
            _size -= 1;
        }
        return position;
    }

    iterator erase(iterator first, iterator last)
    {
        Node<value_type> *temp = _node_begin;

        for (iterator it = begin() ; it != first ; it++)
            temp = temp->next;
        if (last == end())
        {
            while (end() != first)
                pop_back();
            return end();
        }
        while (first != last)
            first = erase(first);
        return (last);
    }

    void swap(List &x)
    {
        std::swap(x._node_begin, _node_begin);
        std::swap(x._size, _size);
        std::swap(x._node_end, _node_end);
    }

    void resize(size_type n, value_type val = value_type())
    {
        if (n == _size)
            return ;
        if (n < _size)
        {
            while (_size > n)
                this->pop_back();
        }
        else
        {
            while (_size < n)
                this->push_back(val);
        }
    }

    void clear()
    {
        while (_size)
            this->pop_front();
    }

    /* OPERATIONS */

    void splice(iterator position, List &x)
    {
        if (x.empty())
            return ;

        bool em = empty();
        Node<value_type> *temp = em ? _node_begin : _node_begin->prev;
        Node<value_type> *temp2 = x._node_begin;
        Node<value_type> *temp3 = x._node_end->prev;
        iterator it = begin();

        while (it != position)
        {
            temp = temp->next;
            it++;
        }
        x._node_begin->prev->next = x._node_end;
        x._node_end->prev = x._node_begin->prev;
        x._node_begin = x._node_begin->prev;
        Node<value_type> *temp4 = temp->next;
        if (position == begin() || em)
            _node_begin = temp2;
        temp->next = temp2;
        temp2->prev = temp;
        temp3->next = temp4;
        temp4->prev = temp3;
        _size += x._size;
        x._size = 0;
    }

    void splice(iterator position, List &x, iterator i)
    {
        bool em = empty();
        Node<value_type> *temp = em ? _node_begin : _node_begin->prev;
        Node<value_type> *temp2 = x._node_begin;
        Node<value_type> *temp3;
        if (x._size <= 1) {splice(position, x); return;}
        iterator it = begin();
        iterator it2 = x.begin();
        while (it != position)
        {
            temp = temp->next;
            it++;
        }
        while (it2 != i)
        {
            temp2 = temp2->next;
            it2++;
        }
        temp2->prev->next = temp2->next;
        temp2->next->prev = temp2->prev;
        temp3 = temp->next;
        if (position == begin() || em)
            _node_begin = temp2;
        if (i == x.begin())
            x._node_begin = x._node_begin->next;
        temp->next = temp2;
        temp2->prev = temp;
        temp2->next = temp3;
        temp3->prev = temp2;
        x._size -= 1;
        _size += 1;
    }

    void splice(iterator position, List &x, iterator first, iterator last)
    {
        bool em = empty();
        Node<value_type> *temp = em ? _node_begin : _node_begin->prev;
        Node<value_type> *temp2 = x._node_begin;
        Node<value_type> *temp3;
        Node<value_type> *temp4;
        if (x._size <= 1) {splice(position, x); return;}
        iterator it = begin();
        iterator it2 = x.begin();
        while (it != position)
        {
            temp = temp->next;
            it++;
        }
        while (it2 != first)
        {
            temp2 = temp2->next;
            it2++;
        }
        temp3 = temp2;
        while (it2 != last)
        {
            temp3 = temp3->next;
            it2++;
            _size++;
            x._size--;
        }
        _size++;
        x._size--;
        if (position == begin() || em)
            _node_begin = temp2;
        if (first == x.begin())
            x._node_begin = temp3->next;
        temp4 = temp->next;
        temp2->prev->next = temp3->next;
        temp3->next->prev = temp2->prev;
        temp->next = temp2;
        temp2->prev = temp;
        temp3->next = temp4;
        temp4->prev = temp3;
    }

    void remove(const value_type &val)
    {
        for (iterator it = begin() ; it != end() ; it++)
        {
            if (*it == val)
            {
                it = erase(it);
                it--;
            }
            if (!_size) break ;
        }
    }

    template <class Predicate>
    void remove_if(Predicate pred)
    {
        for (iterator it = begin() ; it != end() ; it++)
        {
            if (pred(*it))
            {
                it = erase(it);
                it--;
            }
            if (!_size) break ;
        }
    }

    void unique()
    {
        if (!_size) return;
        iterator ite = begin();
        ite++;
        value_type temp = *begin();

        for (iterator it = ite ; it != end() ; it++)
        {
            while (*it == temp)
            {
                it = erase(it);
                if (it == end())
                    return ;
            }
            temp = *it;
        }
    }

    template <class BinaryPredicate>
    void unique(BinaryPredicate binary_pred)
    {
        if (!_size) return;
        iterator ite = begin();
        ite++;
        value_type temp = *begin();

        for (iterator it = ite ; it != end() ; it++)
        {
            while (binary_pred(temp, *it))
            {
                it = erase(it);
                if (it == end())
                    return ;
            }
            temp = *it;
        }
    }
    
    void merge(List &x)
    {
        for (iterator it = begin() ; it != end() ; it++)
        {
            while (*(x.begin()) < *it)
            {
                splice(it, x, x.begin());
                if (x.empty())
                    return ;
            }
        }
        splice(end(), x);
    }

    template <class Compare>
    void merge(List &x, Compare comp)
    {
        for (iterator it = begin() ; it != end() ; it++)
        {
            while (comp((*x.begin()), *it))
            {
                splice(it, x, x.begin());
                if (x.empty())
                    return ;
            }
        }
        splice(end(), x);
    }

    void sort()
    {
        int swapped;
        Node<value_type> *temp;
        
        if (empty()) return ;
        do
        {
            swapped = 0;
            temp = _node_begin;
            while (temp->next != _node_end)
            {
                if (temp->elem > temp->next->elem)
                {
                    std::swap(temp->elem, temp->next->elem);
                    swapped = 1;
                }
                temp = temp->next;
            }
            temp = _node_end;
        }
        while (swapped);
    }

    template <class Compare>
    void sort(Compare comp)
    {
        int swapped;
        Node<value_type> *temp;
        
        if (empty()) return ;
        do
        {
            swapped = 0;
            temp = _node_begin;
            while (temp->next != _node_end)
            {
                if (comp(temp->next->elem, temp->elem))
                {
                    std::swap(temp->elem, temp->next->elem);
                    swapped = 1;
                }
                temp = temp->next;
            }
            temp = _node_end;
        }
        while (swapped);
    }

    void reverse()
    {
        Node<value_type> *temp0 = _node_begin->prev;
        Node<value_type> *temp2;
        Node<value_type> *temp = _node_begin;

        if (_size <= 1) return ;
        while (temp != _node_end)
        {
            temp2 = temp->prev;
            temp->prev = temp->next;
            temp->next = temp2;
            temp = temp->prev;
        }
        _node_begin = _node_end->prev;
        _node_begin->prev = _node_end;
        _node_begin->prev->next = _node_begin;
        _node_end = temp0;
        _node_end->prev = temp0->next;

    }

    /* DISPATCH FUNCTIONS */

private:

    void input_dispatch(size_t n, value_type &val)
    {
        init_list();
        for (size_t i = 0 ; i < n ; i++)
            push_back(val);
    }

    template <class T1>
    void input_dispatch(T1 *first, T1 *last)
    {
        init_list();
        while (first != last)
        {
            this->push_back(*first);
            first++;
        }
    }

    void input_dispatch(iterator first, iterator last)
    {
        init_list();
        while (first != last)
        {
            this->push_back(*first);
            first++;
        }
    }

    void input_dispatch(const_iterator first, const_iterator last)
    {
        init_list();
        while (first != last)
        {
            this->push_back(*first);
            first++;
        }
    }

    void input_dispatch(reverse_iterator first, reverse_iterator last)
    {
        init_list();
        while (first != last)
        {
            this->push_back(*first);
            first++;
        }
    }

    void input_dispatch(const_reverse_iterator first, const_reverse_iterator last)
    {
        init_list();
        while (first != last)
        {
            this->push_back(*first);
            first++;
        }
    }

    void insert_dispatch(iterator position, size_type n, value_type &val)
    {
        for (size_type i = 0 ; i < n ; i++)
            this->insert(position, val);
    }

    void insert_dispatch(iterator position, iterator first, iterator last)
    {
        for (iterator ite = last - 1 ; ite != first - 1 ; ite--)
            this->insert(position, *ite);
    }

    void insert_dispatch(iterator position, reverse_iterator first, reverse_iterator last)
    {
        for (reverse_iterator ite = last - 1 ; ite != first - 1 ; ite--)
            this->insert(position, *ite);
    }

    void insert_dispatch(iterator position, const_iterator first, const_iterator last)
    {
        for (const_iterator ite = last - 1 ; ite != first - 1 ; ite--)
            this->insert(position, *ite);
    }

    void insert_dispatch(iterator position, const_reverse_iterator first, const_reverse_iterator last)
    {
        for (const_reverse_iterator ite = last - 1 ; ite != first - 1 ; ite--)
            this->insert(position, *ite);
    }

    void del_list()
    {
        while (_size)
            this->pop_front();
        delete _node_begin;
        delete _node_end;
    }

    void init_list()
    {
        _size = 0;
        _node_begin = new Node<value_type>;
        _node_begin->elem = value_type();
        _node_end = new Node<value_type>;
        _node_begin->next = _node_end;
        _node_end->prev = _node_begin;
    }
};

template <class T>
void swap(ft::List<T> &x, ft::List<T> &y) {x.swap(y);}


template <class T>
bool operator==(const ft::List<T> &lhs, const ft::List<T> &rhs)
{
    ft::BConstIterator<T> l_it = lhs.begin();
    ft::BConstIterator<T> r_it = rhs.begin();

    if (lhs.size() != rhs.size())
        return false;
    else
    {
        for (size_t i = 0 ; i < lhs.size() ; i++)
        {
            if (*l_it != *r_it)
                return false;
            l_it++;
            r_it++;
        }
    }
    return true;
}

template <class T>
bool operator!=(const ft::List<T> &lhs, const  ft::List<T> &rhs) {return (!(lhs == rhs));}

template <class T>
bool operator<(const ft::List<T> &lhs, const ft::List<T> &rhs)
{
    ft::BConstIterator<T> l_it = lhs.begin();
    ft::BConstIterator<T> r_it = rhs.begin();

    size_t size = std::min(lhs.size(), rhs.size());
    
    for (size_t i = 0 ; i < size ; i++)
    {
            if (*l_it != *r_it)
                return (*l_it < *r_it);
            l_it++;
            r_it++;
    }
    return (lhs.size() < rhs.size());
}

template <class T>
bool operator>=(const ft::List<T> &lhs, const ft::List<T> &rhs) {return !(lhs < rhs);}

template <class T>
bool operator>(const ft::List<T> &lhs, const ft::List<T> &rhs)
{
    ft::BConstIterator<T> l_it = lhs.begin();
    ft::BConstIterator<T> r_it = rhs.begin();

    size_t size = std::min(lhs.size(), rhs.size());
    
    for (size_t i = 0 ; i < size ; i++)
    {
            if (*l_it != *r_it)
                return (*l_it > *r_it);
            l_it++;
            r_it++;
    }
    return (lhs.size() > rhs.size());
}

template <class T>
bool operator<=(const ft::List<T> &lhs, const ft::List<T> &rhs) {return !(lhs > rhs);}
}