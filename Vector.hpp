/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbajrami <tbajrami@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:47:28 by tbajrami          #+#    #+#             */
/*   Updated: 2021/03/16 15:53:12 by tbajrami         ###   ########lyon.fr   */
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
#include "RandomAccessIterator.hpp"

namespace ft
{

template <class T>
class Vector
{
public:

    typedef T value_type;
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
    value_type *_end_cap;

public:

    Vector() : _size(0), _capacity(0), _begin(NULL), _end(NULL), _end_cap(NULL) {};

    Vector(size_t n, const value_type &val)
    {
        size_t i;

        this->_size = n;
        this->_capacity = n;
        this->_begin = new value_type[n];
        for (i = 0 ; i < n ; i++)
            this->_begin[i] = val;
        this->_end = this->_begin + n;
        this->_end_cap = this->_begin + n;
    }

    template <class InputIterator>
    Vector(InputIterator first, InputIterator last, std::enable_if<InputIterator::is_iterator, int> = 0)
    {
        ft::Vector<value_type> nv;
        size_t size = last - first;
        size_t i = 0;

        *this = nv;
        this->_size = size;
        this->_capacity = size;
        this->_begin = new value_type[size];
        while (first != last)
        {
            typename std::iterator_traits<InputIterator>::value_type tmp = *first;
            this->_begin[i] = tmp;
            first++;
            i++;
        }
        this->_end = this->_begin + size;
        this->_end_cap = this->_begin + size;
    }

    ~Vector() {delete [] this->_begin;}

    Vector(const ft::Vector<value_type> &x) : _size(x._size), _capacity(x._capacity)
    {
        this->_begin = new value_type[this->_capacity];
        for (size_t i = 0 ; i < this->_capacity ; i++)
            this->_begin[i] = x._begin[i];
        this->_end = this->_begin + this->_size;
        this->_end_cap = this->_begin + this->_capacity;
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
        this->_end_cap = this->_begin + this->_capacity;
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
        this->_end_cap = this->_begin + this->_capacity;
        this->_size = n;
    }

    void reserve(size_t n)
    {
        if (n <= this->_capacity) return ;
        if (n > this->max_size()) throw std::length_error("");
        this->_capacity = n;
        this->_end_cap = this->_begin + n;
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
        ft::Vector<value_type> nv(n, val);
        size_t cap = this->_capacity < n ? n : this->_capacity;

        *this = nv;
        this->_capacity = cap;
        this->_end_cap = this->_begin + cap;
    }

    // template<class InputIterator>
    // void assign(InputIterator first, InputIterator last)
    // {
        
    // }
};

}