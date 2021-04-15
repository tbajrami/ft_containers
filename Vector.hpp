/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbajrami <tbajrami@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:47:28 by tbajrami          #+#    #+#             */
/*   Updated: 2021/04/14 16:03:34 by tbajrami         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include <vector>
#include <list>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <limits>
#include <iterator>
#include <utility>
#include <typeinfo>
#include "RandomAccessIterator.hpp"

namespace ft
{

template <class T>
class Vector
{
public:

    typedef T value_type;
    typedef size_t size_type;
    typedef ft::Iterator<T> iterator;
    typedef ft::ReverseIterator<T> reverse_iterator;
    typedef ft::ConstIterator<T> const_iterator;
    typedef ft::ReverseConstIterator<T> const_reverse_iterator;

private:

    size_t _size;
    size_t _capacity;


protected:

    value_type *_begin;
    value_type *_end;

public:

    Vector() : _size(0), _capacity(0), _begin(NULL), _end(NULL) {};

    Vector(size_t n, const value_type &val = value_type())
    {
        size_t i;

        this->_size = n;
        this->_capacity = n;
        this->_begin = new value_type[n];
        for (i = 0 ; i < n ; i++)
            this->_begin[i] = val;
        this->_end = this->_begin + n;
    }

    template <class InputIterator>
    Vector(InputIterator first, InputIterator last)
    {
        input_dispatch(first, last);
    }

    ~Vector() {delete [] this->_begin;}

    Vector(const ft::Vector<value_type> &x) : _size(x._size), _capacity(x._capacity)
    {
        this->_begin = new value_type[this->_capacity];
        for (size_t i = 0 ; i < this->_capacity ; i++)
            this->_begin[i] = x._begin[i];
        this->_end = this->_begin + this->_size;
    }

    Vector &operator=(const Vector &rhs)
    {
        delete [] this->_begin;
        this->_size = rhs._size;
        this->_capacity = rhs._capacity;
        this->_begin = new value_type[this->_capacity];
        for (size_t i = 0 ; i < this->_capacity ; i++)
            this->_begin[i] = rhs._begin[i];
        this->_end = this->_begin + this->_size;
        return *this;
    }

    /* ITERATORS */

    iterator begin()
    {
        iterator it;
        it.setPtr(this->_begin);
        return it;
    }

    iterator end()
    {
        iterator it;
        it.setPtr(this->_end);
        return it;
    }

    reverse_iterator rbegin()
    {
        reverse_iterator it;
        it.setPtr(this->_end - 1);
        return it;
    }

    reverse_iterator rend()
    {
        reverse_iterator it;
        it.setPtr(this->_begin - 1);
        return it;
    }

    const_iterator begin() const
    {
        const_iterator it;
        it.setPtr(this->_begin);
        return it;
    }

    const_iterator end() const
    {
        const_iterator it;
        it.setPtr(this->_end);
        return it;
    }

    const_reverse_iterator rbegin() const
    {
        const_reverse_iterator it;
        it.setPtr(this->_end - 1);
        return it;
    }

    const_reverse_iterator rend() const
    {
        const_reverse_iterator it;
        it.setPtr(this->_begin - 1);
        return it;
    }

    /* SIZE */

    size_t size() const {return this->_size;}
    size_t max_size() const {return std::numeric_limits<size_t>::max() / sizeof(value_type);}
    size_t capacity() const {return this->_capacity;}
    bool   empty() const {return !this->_size;}

    void resize(size_t n, value_type val = value_type())
    {
        if (n == this->_size) return ;
        
        if (n < this->_capacity);
        else if (n <= this->_capacity * 2)
            this->_capacity *= 2;
        else if (n > this->_capacity * 2)
            this->_capacity = n;

        value_type *new_vec = new value_type[this->_capacity];
        
        for (size_t i = 0 ; i < n ; i++)
            new_vec[i] = (i < this->_size) ? this->at(i) : val;
        delete [] this->_begin;
        this->_begin = new_vec;
        this->_end = this->_begin + n;
        this->_size = n;
    }

    void reserve(size_t n)
    {
        if (n <= this->_capacity) return ;
        if (n > this->max_size()) throw std::length_error("");
        value_type *new_vec = new value_type[n];
        for (size_t i = 0 ; i < this->_size ; i++)
            new_vec[i] = this->at(i);
        delete [] this->_begin;
        this->_begin = new_vec;
        this->_end = this->_begin + this->_size;
        this->_capacity = n;
    }

    /* ELEMENT ACCESS */

    value_type &at(size_t n)
    {
        if (n >= this->_size)
            throw std::out_of_range("");
        return *(this->_begin + n);
    }

    const value_type &at(size_t n) const
    {
        if (n >= this->_size)
            throw std::out_of_range("");
        return *(this->_begin + n);
    }

    value_type &operator[](size_t n) {return this->at(n);}
    const value_type &operator[](size_t n) const {return this->at(n);}
    
    value_type &front() {return this->at(0);}
    const value_type &front() const {return this->at(0);}
    
    value_type &back() {return this->at(this->_size - 1);}
    const value_type &back() const {return this->at(this->_size - 1);}

    /* MODIFIERS */

    void assign(size_t n, const value_type &val)
    {
        ft::Vector<value_type> nv;

        nv.input_dispatch(n, val);
        size_t cap = this->_capacity < n ? n : this->_capacity;

        *this = nv;
        this->_capacity = cap;
    }

    template<class InputIterator>
    void assign(InputIterator first, InputIterator last)
    {
        ft::Vector<value_type> nv;

        nv.input_dispatch(first, last);
        if (nv._size < this->_size)
            nv.reserve(this->_size);
        *this = nv;
    }

    void push_back(const value_type &val)
    {
        if (this->empty())
        {
            this->_begin = new value_type;
            this->_end = this->_begin;
            this->_capacity = 1;
        }
        else if (this->_size == this->_capacity)
            this->reserve(2 * this->_capacity);
        this->_size += 1;
        this->_begin[this->_size - 1] = val;
        this->_end = this->_begin + this->_size;
    }

    void pop_back()
    {
        if (!this->empty())
        {
            this->_size -= 1;
            this->_end = this->_begin + this->_size;
        }
    }

    iterator insert(iterator position, const value_type &val)
    {
        int i = 0;
        size_t s = _size;
        iterator itf;

        for (iterator ite = begin() ; ite != position ; ite++)
            i++;
        push_back(0);
        if (s != _size)
        {
            itf = begin();
            for (int j = 0 ; j != i ; j++)
                itf++;
            position = itf;
        }
        for (iterator ite = end() - 1 ; ite != position ; ite--)
            *ite = *(ite - 1);
        *position = val;
        return position;
    }

    void insert(iterator position, size_type n, const value_type &val)
    {
        for (size_t i = 0 ; i < n ; i++)
            this->insert(position, val);
    }

    template <class InputIterator>
    void insert (iterator position, InputIterator first, InputIterator last) {insert_dispatch(position, first, last);}

    iterator erase(iterator position)
    {
        for (iterator ite = position ; ite != this->end() - 1 ; ite++)
            *ite = *(ite + 1);
        this->pop_back();
        return position;
    }

    iterator erase(iterator first, iterator last)
    {
        int i = 0;
        for (iterator pos = first ; pos != last ; pos++)
            i++;
        for (int j = 0 ; j != i ; j++)
            this->erase(first);
        return first;
    }

    void swap(Vector &x)
    {
        std::swap(x._begin, this->_begin);
        std::swap(x._size, this->_size);
        std::swap(x._end, this->_end);
        std::swap(x._capacity, this->_capacity);
    }

    void clear()
    {
        while (!this->empty())
            this->pop_back();
    }

    /* DISPATCH FUNCTION TEMPLATES */

private:

    void input_dispatch(size_t n, const value_type &val)
    {
        _size = n;
        _capacity = n;
        _begin = new value_type[n];
        for (size_t i = 0 ; i < n ; i++)
            _begin[i] = val;
        _end = _begin + n;
    }

    template <class T1>
    void input_dispatch(T1 *first, T1 *last)
    {
        size_t size = last - first;
        size_t i = 0;

        _size = size;
        _capacity = size;
        _begin = new value_type[size];
        while (first != last)
        {
            _begin[i] = *first;
            first++;
            i++;
        }
        _end = _begin + size;
    }

    template <class InputIterator>
    void input_dispatch(InputIterator first, InputIterator last)
    {
        size_t size = last - first;
        size_t i = 0;

        _size = size;
        _capacity = size;
        _begin = new value_type[size];
        while (first != last)
        {
            _begin[i] = *first;
            first++;
            i++;
        }
        _end = _begin + size;
    }

    void input_dispatch(iterator first, iterator last)
    {
        size_t size = last - first;
        size_t i = 0;

        _size = size;
        _capacity = size;
        _begin = new value_type[size];
        while (first != last)
        {
            _begin[i] = *first;
            first++;
            i++;
        }
        _end = _begin + size;
    }

    void input_dispatch(const_iterator first, const_iterator last)
    {
        size_t size = last - first;
        size_t i = 0;

        _size = size;
        _capacity = size;
        _begin = new value_type[size];
        while (first != last)
        {
            _begin[i] = *first;
            first++;
            i++;
        }
        _end = _begin + size;
    }

    void input_dispatch(reverse_iterator first, reverse_iterator last)
    {
        size_t size = first - last;
        size_t i = 0;

        _size = size;
        _capacity = size;
        _begin = new value_type[size];
        while (first != last)
        {
            _begin[i] = *first;
            first++;
            i++;
        }
        _end = _begin + size;
    }

    void input_dispatch(const_reverse_iterator first, const_reverse_iterator last)
    {
        size_t size = first - last;
        size_t i = 0;

        _size = size;
        _capacity = size;
        _begin = new value_type[size];
        while (first != last)
        {
            _begin[i] = *first;
            first++;
            i++;
        }
        _end = _begin + size;
    }

    void insert_dispatch(iterator position, size_type n, const value_type &val)
    {
        for (size_t i = 0 ; i < n ; i++)
            this->insert(position, val);
    }

    template <class T1>
    void insert_dispatch(iterator position, T1 *first, T1 *last)
    {
        while (last != first)
        {
            position = insert(position, *--last);
        }
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

    friend void std::swap(ft::Vector<T> &x, ft::Vector<T> &y);
};

template <class T>
void swap(ft::Vector<T> &x, ft::Vector<T> &y) {x.swap(y);}

template <class T>
bool operator==(const ft::Vector<T> &lhs, const ft::Vector<T> &rhs)
{
    if (lhs.size() != rhs.size())
        return false;
    else
    {
        for (size_t i = 0 ; i < lhs.size() ; i++)
        {
            if (lhs[i] != rhs[i])
                return false;
        }
    }
    return true;
}

template <class T>
bool operator!=(const ft::Vector<T> &lhs, const  ft::Vector<T> &rhs) {return (!(lhs == rhs));}

template <class T>
bool operator<(const ft::Vector<T> &lhs, const ft::Vector<T> &rhs)
{
    size_t size = std::min(lhs.size(), rhs.size());
    
    for (size_t i = 0 ; i < size ; i++)
    {
        if (lhs[i] != rhs[i])
            return (lhs[i] < rhs[i]);
    }
    return (lhs.size() < rhs.size());
}

template <class T>
bool operator>=(const ft::Vector<T> &lhs, const ft::Vector<T> &rhs) {return !(lhs < rhs);}

template <class T>
bool operator>(const ft::Vector<T> &lhs, const ft::Vector<T> &rhs)
{
    size_t size = std::min(lhs.size(), rhs.size());
    
    for (size_t i = 0 ; i < size ; i++)
    {
        if (lhs[i] != rhs[i])
            return (lhs[i] > rhs[i]);
    }
    return (lhs.size() > rhs.size());
}

template <class T>
bool operator<=(const ft::Vector<T> &lhs, const ft::Vector<T> &rhs) {return !(lhs > rhs);}

}