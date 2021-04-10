/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbajrami <tbajrami@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 12:22:38 by tbajrami          #+#    #+#             */
/*   Updated: 2021/04/10 16:15:42 by tbajrami         ###   ########lyon.fr   */
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
    size_type _size;

public:

    explicit List() : _node_begin(NULL), _node_end(NULL), _size(0) {}
    explicit List(size_type n, const value_type &val = value_type())
    {
        _node_begin = new Node<value_type>;
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
        it.setPtr(_node_end);
        return it;
    }

    const_iterator end() const
    {
        const_iterator it;
        it.setPtr(_node_end);
        return it;
    }

    reverse_iterator rbegin()
    {
        reverse_iterator it;
        it.setPtr(_node_end->prev);
        return it;
    }

    const_reverse_iterator rbegin() const
    {
        const_reverse_iterator it;
        it.setPtr(_node_end->prev);
        return it;
    }

    reverse_iterator rend()
    {
        reverse_iterator it;
        it.setPtr(_node_begin->prev);
        return it;
    }

    const_iterator rend() const
    {
        const_reverse_iterator it;
        it.setPtr(_node_begin->prev);
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
        Node<value_type> *n = new Node<value_type>;

        _node_begin->prev = n;
        n->elem = val;
        n->next = _node_begin;
        n->prev = NULL;
        _node_begin = n;
        _size += 1;
    }

    void pop_front()
    {
        _node_begin = _node_begin->next;
        delete _node_begin->prev;
        _node_begin->prev = NULL;
        _size -= 1;
    }

    void push_back(const value_type &val)
    {
        Node<value_type> *n = new Node<value_type>;

        _node_end->elem = val;
        _node_end->next = n;
        n->prev = _node_end;
        _node_end = n;
        _size += 1;
    }

    void pop_back()
    {
        _node_end = _node_end->prev;
        delete _node_end->next;
        _node_end->next = NULL;
        _size -= 1;
    }
};

}