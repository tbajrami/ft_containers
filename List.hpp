/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbajrami <tbajrami@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 12:22:38 by tbajrami          #+#    #+#             */
/*   Updated: 2021/04/12 13:26:32 by tbajrami         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <list>
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
        _node_begin = new Node<value_type>;
        _node_begin->prev = new Node<value_type>;
        _node_begin->prev->next = _node_begin;
        Node<value_type> *temp = _node_begin;

        for (size_t i = 0 ; i < n ; i++)
        {
            Node<value_type> *prev = temp;

            temp->elem = val;
            temp->next = new Node<value_type>;
            temp = temp->next;
            temp->prev = prev;
            temp->prev->next = temp;
        }
        _node_end = temp;
        _size = n;
    }

    List(const List &x) {input_dispatch(x.begin(), x.end());}

    List &operator=(const List &x)
    {
        this->del_list();
        input_dispatch(x.begin(), x.end());
        return *this;
    }

    template <class InputIterator>
    List (InputIterator first, InputIterator last) : _size(0)
    {
        input_dispatch(first, last);
    }

    ~List() {this->del_list();}

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
        if (_size != 0)
            it.setPtr(_node_end);
        else
            it.setPtr(_node_begin);
        return it;
    }

    const_iterator end() const
    {
        const_iterator it;
        if (_size != 0)
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
            _node_begin->elem = val;
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
        if (_size)
        {
            delete _node_begin->prev;
            _node_begin = _node_begin->next;
            _size -= 1;
        }
    }

    void push_back(const value_type &val)
    {

        if (_size == 0)
            _node_begin->elem = val;
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
        if (_size)
        {
            _node_end = _node_end->prev;
            delete _node_end->next;
            _node_end->next = NULL;
            _size -= 1;
        }
    }

    /* DISPATCH FUNCTIONS */

private:

    void input_dispatch(size_t n, value_type &val)
    {
        _node_begin = new Node<value_type>;
        _node_begin->prev = new Node<value_type>;
        _node_begin->prev->next = _node_begin;
        Node<value_type> *temp = _node_begin;

        for (size_t i = 0 ; i < n ; i++)
        {
            Node<value_type> *prev = temp;

            temp->elem = val;
            temp->next = new Node<value_type>;
            temp = temp->next;
            temp->prev = prev;
            temp->prev->next = temp;
        }
        _node_end = temp;
        _size = n;
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

    void del_list()
    {
        while (_size)
            this->pop_back();
        delete _node_begin->prev;
        delete _node_begin->next;
        delete _node_begin;
    }

    void init_list()
    {
        _node_begin = new Node<value_type>;
        _node_begin->prev = new Node<value_type>;
        _node_end = new Node<value_type>;
        _node_begin->prev->next = _node_begin;
        _node_begin->next = _node_end;
        _node_end->prev = _node_begin;
        _node_begin->elem = value_type();
    }
};
}