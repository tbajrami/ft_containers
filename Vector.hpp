/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbajrami <tbajrami@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:47:28 by tbajrami          #+#    #+#             */
/*   Updated: 2021/03/01 15:33:17 by tbajrami         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include <vector>
#include <list>

namespace ft
{

template <class T>
class Vector
{
protected:

    T *_begin;
    T *_end;
    T *_end_cap;

public:

    typedef T value_type;

    explicit Vector() : _begin(NULL), _end(NULL), _end_cap(NULL) {};

    explicit Vector(size_t n, const value_type &val)
    {
        this->_begin = new value_type[(n + 3) * sizeof(value_type)];
        for (int i = 0 ; i < n ; i++)
            *(this->_begin + i * (sizeof(value_type))) = val;
    }

};

}