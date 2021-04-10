/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbajrami <tbajrami@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 12:00:38 by tbajrami          #+#    #+#             */
/*   Updated: 2021/04/10 12:17:58 by tbajrami         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Vector.hpp"

namespace ft
{

template <class T, class Container = ft::Vector<T> >
class Queue
{
public:
    typedef Container                                container_type;
    typedef typename container_type::value_type      value_type;
    typedef typename container_type::size_type       size_type;

protected:
    container_type c;

public:
    explicit Queue(const container_type &ctnr = container_type()) {c = ctnr;}
    ~Queue() {}

    bool empty() const {return c.empty();}
    size_type size() const {return c.size();}
    value_type &front() {return c.front();}
    const value_type &front() const {return c.front();}
    value_type &back() {return c.back();}
    const value_type &back() const {return c.back();}
    void push(const value_type &val) {c.push_back(val);}
    void pop() {c.erase(c.begin());}

    template <class T1>
    friend bool operator==(const ft::Queue<T1> &lhs, const ft::Queue<T1> &rhs);
    template <class T1>
    friend bool operator!=(const ft::Queue<T1> &lhs, const ft::Queue<T1> &rhs);
    template <class T1>
    friend bool operator<(const ft::Queue<T1> &lhs, const ft::Queue<T1> &rhs);
    template <class T1>
    friend bool operator>(const ft::Queue<T1> &lhs, const ft::Queue<T1> &rhs);
    template <class T1>
    friend bool operator<=(const ft::Queue<T1> &lhs, const ft::Queue<T1> &rhs);
    template <class T1>
    friend bool operator>=(const ft::Queue<T1> &lhs, const ft::Queue<T1> &rhs);
};

template <class T>
bool operator==(const ft::Queue<T> &lhs, const ft::Queue<T> &rhs) {return (lhs.c == rhs.c);}
template <class T>
bool operator!=(const ft::Queue<T> &lhs, const ft::Queue<T> &rhs) {return (lhs.c != rhs.c);}
template <class T>
bool operator<(const ft::Queue<T> &lhs, const ft::Queue<T> &rhs) {return (lhs.c < rhs.c);}
template <class T>
bool operator>(const ft::Queue<T> &lhs, const ft::Queue<T> &rhs) {return (lhs.c > rhs.c);}
template <class T>
bool operator<=(const ft::Queue<T> &lhs, const ft::Queue<T> &rhs) {return (lhs.c <= rhs.c);}
template <class T>
bool operator>=(const ft::Queue<T> &lhs, const ft::Queue<T> &rhs) {return (lhs.c >= rhs.c);}

};