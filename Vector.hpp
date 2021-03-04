/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbajrami <tbajrami@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:47:28 by tbajrami          #+#    #+#             */
/*   Updated: 2021/03/04 14:40:46 by tbajrami         ###   ########lyon.fr   */
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

namespace ft
{

template <class T>
class Vector
{
public:

    typedef T value_type;

private:

    size_t _size;
    size_t _capacity;

protected:

    value_type *_begin;
    value_type *_end;
    value_type *_end_cap;

public:

    class iterator
    {
    public:
        value_type   *_ptr;
    };

    Vector::iterator begin()
    {
        Vector::iterator it;
        it._ptr = this->_begin;
    }

    Vector::iterator end()
    {
        Vector::iterator it;
        it._ptr = this->_begin;
    }

    explicit Vector() : _size(0), _capacity(0), _begin(NULL), _end(NULL), _end_cap(NULL) {};

    explicit Vector(size_t n, const value_type &val)
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

    ~Vector() {delete [] this->_begin;}

    // Vector(const ft::Vector<value_type> &x)
    // {}

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

    value_type &operator[](size_t n) {return at(n);}
};

}