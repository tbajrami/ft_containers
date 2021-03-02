/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbajrami <tbajrami@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:47:28 by tbajrami          #+#    #+#             */
/*   Updated: 2021/03/02 12:30:47 by tbajrami         ###   ########lyon.fr   */
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



    explicit Vector() : _size(0), _capacity(0), _begin(NULL), _end(NULL), _end_cap(NULL) {};

    explicit Vector(size_t n, const value_type &val)
    {
        size_t j;
        size_t i;

        for (j = 0 ; pow(2, j) < n ; j++);
        int k = pow(2, j);
        this->_size = n;
        this->_capacity = k;
        this->_begin = new value_type[k];
        for (i = 0 ; i < n ; i++)
            this->_begin[i] = val;
        this->_end = this->_begin + n;
    }

    ~Vector() {delete [] this->_begin;}

    // Vector(const ft::Vector<value_type> &x)
    // {}

    /* SIZE */

    size_t size() const {return this->_size;}
    size_t max_size() const {return std::numeric_limits<size_t>::max();}
    size_t capacity() const {return this->_capacity;}

    void resize(size_t n, value_type val = value_type())
    {
        if (n == this->_size) return ;
        
        value_type *new_vec = new value_type[n];
        
        for (size_t i = 0 ; i < n ; i++)
            new_vec[i] = (i < this->_size) ? this->at(i) : val;
        delete [] this->_begin;
        this->_begin = new_vec;
        this->_end = this->_begin + n;
        this->_end_cap = this->_begin + n;
        this->_size = n;
        this->_capacity = n;
    }

    /* ELEMENT ACCESS */

    value_type &at(size_t n)
    {
        if (n >= this->_size)
            throw std::out_of_range("");
        return *(this->_begin + n);
    }
};

}