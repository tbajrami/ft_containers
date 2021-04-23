/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbajrami <tbajrami@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:47:32 by tbajrami          #+#    #+#             */
/*   Updated: 2021/04/23 10:43:40 by tbajrami         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Vector.hpp"

namespace ft
{

template <class T, class Container = ft::Vector<T> >
class Stack
{
public:
    typedef Container                                container_type;
    typedef typename container_type::value_type      value_type;
    typedef typename container_type::size_type       size_type;

protected:
    container_type c;

public:
    explicit Stack() {}
    ~Stack() {}

    bool empty() const {return c.empty();}
    size_type size() const {return c.size();}
    value_type &top() {return c.back();}
    const value_type &top() const {return c.back();}
    void push(const value_type &val) {c.push_back(val);}
    void pop() {c.pop_back();}

    template <class T1>
    friend bool operator==(const ft::Stack<T1> &lhs, const ft::Stack<T1> &rhs);
    template <class T1>
    friend bool operator!=(const ft::Stack<T1> &lhs, const ft::Stack<T1> &rhs);
    template <class T1>
    friend bool operator<(const ft::Stack<T1> &lhs, const ft::Stack<T1> &rhs);
    template <class T1>
    friend bool operator>(const ft::Stack<T1> &lhs, const ft::Stack<T1> &rhs);
    template <class T1>
    friend bool operator<=(const ft::Stack<T1> &lhs, const ft::Stack<T1> &rhs);
    template <class T1>
    friend bool operator>=(const ft::Stack<T1> &lhs, const ft::Stack<T1> &rhs);
};

template <class T>
bool operator==(const ft::Stack<T> &lhs, const ft::Stack<T> &rhs) {return (lhs.c == rhs.c);}
template <class T>
bool operator!=(const ft::Stack<T> &lhs, const ft::Stack<T> &rhs) {return (lhs.c != rhs.c);}
template <class T>
bool operator<(const ft::Stack<T> &lhs, const ft::Stack<T> &rhs) {return (lhs.c < rhs.c);}
template <class T>
bool operator>(const ft::Stack<T> &lhs, const ft::Stack<T> &rhs) {return (lhs.c > rhs.c);}
template <class T>
bool operator<=(const ft::Stack<T> &lhs, const ft::Stack<T> &rhs) {return (lhs.c <= rhs.c);}
template <class T>
bool operator>=(const ft::Stack<T> &lhs, const ft::Stack<T> &rhs) {return (lhs.c >= rhs.c);}

};