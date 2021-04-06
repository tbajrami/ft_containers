/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbajrami <tbajrami@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 07:44:47 by tbajrami          #+#    #+#             */
/*   Updated: 2021/04/06 15:35:00 by tbajrami         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once


namespace ft
{
template<class T>
class Iterator
{
    public:
        
        typedef T value_type;
        enum {is_iterator = true};

    private:

        value_type   *_ptr;

    public:
    
    /* canonical functions */

        Iterator() {};
        virtual ~Iterator() {};
        Iterator &operator=(const Iterator &rhs) {this->_ptr = rhs._ptr ; return *this;}
        Iterator(const Iterator &ref) : _ptr(ref._ptr) {}
        void setPtr(value_type *ptr) {this->_ptr = ptr;}

    /* operators */

        bool operator==(const Iterator &rhs) const {return (this->_ptr == rhs._ptr);}
        bool operator!=(const Iterator &rhs) const {return (this->_ptr != rhs._ptr);}
        bool operator<=(const Iterator &rhs) const {return (this->_ptr <= rhs._ptr);}
        bool operator>=(const Iterator &rhs) const {return (this->_ptr >= rhs._ptr);}
        bool operator<(const Iterator &rhs) const {return (this->_ptr < rhs._ptr);}
        bool operator>(const Iterator &rhs) const {return (this->_ptr > rhs._ptr);}
        
        value_type &operator*() const {return *(this->_ptr);}
        value_type *operator->() {return this->_ptr;}
        value_type &operator[](int n) const {return *(this->_ptr + n);}
        
        Iterator   operator++() {this->_ptr += 1; return (*this);}
        Iterator   operator++(int i)
        {
            if (!i)
                i = 1;
            Iterator n(*this);
            this->_ptr += i;
            return (n);
        }
        Iterator   operator--() {this->_ptr -= 1; return (*this);}
        Iterator   operator--(int i)
        {
            if (!i)
                i = 1;
            Iterator n(*this);
            this->_ptr -= i;
            return (n);
        }

        Iterator operator+(int n) {this->_ptr += n ; return (*this);}
        Iterator operator-(int n) {this->_ptr -= n ; return (*this);}

        Iterator operator+=(int n) {this->_ptr += n; return (*this);}
        Iterator operator-=(int n) {this->_ptr -= n; return (*this);}

        int      operator-(Iterator const &rhs) {return (this->_ptr - rhs._ptr);}
};

template <class T>
class ReverseIterator
{
    public:
        typedef T value_type;
        typedef value_type is_iterator;

    private:
        value_type   *_ptr;

    public:
    
    /* canonical functions */

        ReverseIterator() {};
        virtual ~ReverseIterator() {};
        ReverseIterator &operator=(const ReverseIterator &rhs) {this->_ptr = rhs._ptr ; return *this;}
        ReverseIterator(const ReverseIterator &ref) : _ptr(ref._ptr) {}
        void setPtr(value_type *ptr) {this->_ptr = ptr;}

    /* operators */

        bool operator==(const ReverseIterator &rhs) const {return (this->_ptr == rhs._ptr);}
        bool operator!=(const ReverseIterator &rhs) const {return (this->_ptr != rhs._ptr);}
        bool operator<=(const ReverseIterator &rhs) const {return (this->_ptr <= rhs._ptr);}
        bool operator>=(const ReverseIterator &rhs) const {return (this->_ptr >= rhs._ptr);}
        bool operator<(const ReverseIterator &rhs) const {return (this->_ptr < rhs._ptr);}
        bool operator>(const ReverseIterator &rhs) const {return (this->_ptr > rhs._ptr);}
        
        value_type &operator*() const {return *(this->_ptr);}
        value_type *operator->() {return this->_ptr;}
        value_type &operator[](int n) const {return *(this->_ptr - n);}
        
        ReverseIterator   operator++() {this->_ptr -= 1; return (*this);}
        ReverseIterator   operator++(int i)
        {
            if (!i)
                i = 1;
            ReverseIterator n(*this);
            this->_ptr -= i;
            return (n);
        }
        ReverseIterator   operator--() {this->_ptr += 1; return (*this);}
        ReverseIterator   operator--(int i)
        {
            if (!i)
                i = 1;
            ReverseIterator n(*this);
            this->_ptr += i;
            return (n);
        }

        ReverseIterator operator+(int n) {this->_ptr -= n ; return (*this);}
        ReverseIterator operator-(int n) {this->_ptr += n ; return (*this);}

        ReverseIterator operator+=(int n) {this->_ptr -= n; return (*this);}
        ReverseIterator operator-=(int n) {this->_ptr += n; return (*this);}

        int      operator-(ReverseIterator const &rhs) {return (this->_ptr - rhs._ptr);}
};

template <class T>
class ConstIterator
{
    public:
        typedef T value_type;
        typedef value_type is_iterator;

    private:
        value_type   *_ptr;

    public:
    
    /* canonical functions */

        ConstIterator() {};
        virtual ~ConstIterator() {};
        ConstIterator &operator=(const ConstIterator &rhs) {this->_ptr = rhs._ptr ; return *this;}
        ConstIterator(const ConstIterator &ref) : _ptr(ref._ptr) {}
        void setPtr(value_type *ptr) {this->_ptr = ptr;}

    /* operators */

        bool operator==(const ConstIterator &rhs) const {return (this->_ptr == rhs._ptr);}
        bool operator!=(const ConstIterator &rhs) const {return (this->_ptr != rhs._ptr);}
        bool operator<=(const ConstIterator &rhs) const {return (this->_ptr <= rhs._ptr);}
        bool operator>=(const ConstIterator &rhs) const {return (this->_ptr >= rhs._ptr);}
        bool operator<(const ConstIterator &rhs) const {return (this->_ptr < rhs._ptr);}
        bool operator>(const ConstIterator &rhs) const {return (this->_ptr > rhs._ptr);}
        
        const value_type &operator*() const {return *(this->_ptr);}
        const value_type *operator->() {return this->_ptr;}
        const value_type &operator[](int n) const {return *(this->_ptr + n);}
        
        ConstIterator   operator++() {this->_ptr += 1; return (*this);}
        ConstIterator   operator++(int i)
        {
            if (!i)
                i = 1;
            ConstIterator n(*this);
            this->_ptr += i;
            return (n);
        }
        ConstIterator   operator--() {this->_ptr -= 1; return (*this);}
        ConstIterator   operator--(int i)
        {
            if (!i)
                i = 1;
            ConstIterator n(*this);
            this->_ptr -= i;
            return (n);
        }

        ConstIterator operator+(int n) {this->_ptr += n ; return (*this);}
        ConstIterator operator-(int n) {this->_ptr -= n ; return (*this);}

        ConstIterator operator+=(int n) {this->_ptr += n; return (*this);}
        ConstIterator operator-=(int n) {this->_ptr -= n; return (*this);}

};

template <class T>
class ReverseConstIterator
{
    public:
        typedef T value_type;
        typedef value_type is_iterator;

    private:
        value_type   *_ptr;

    public:
    
    /* canonical functions */

        ReverseConstIterator() {};
        virtual ~ReverseConstIterator() {};
        ReverseConstIterator &operator=(const ReverseConstIterator &rhs) {this->_ptr = rhs._ptr ; return *this;}
        ReverseConstIterator(const ReverseConstIterator &ref) : _ptr(ref._ptr) {}
        void setPtr(value_type *ptr) {this->_ptr = ptr;}

    /* operators */

        bool operator==(const ReverseConstIterator &rhs) const {return (this->_ptr == rhs._ptr);}
        bool operator!=(const ReverseConstIterator &rhs) const {return (this->_ptr != rhs._ptr);}
        bool operator<=(const ReverseConstIterator &rhs) const {return (this->_ptr <= rhs._ptr);}
        bool operator>=(const ReverseConstIterator &rhs) const {return (this->_ptr >= rhs._ptr);}
        bool operator<(const ReverseConstIterator &rhs) const {return (this->_ptr < rhs._ptr);}
        bool operator>(const ReverseConstIterator &rhs) const {return (this->_ptr > rhs._ptr);}
        
        const value_type &operator*() const {return *(this->_ptr);}
        const value_type *operator->() {return this->_ptr;}
        const value_type &operator[](int n) const {return *(this->_ptr - n);}
        
        ReverseConstIterator   operator++() {this->_ptr -= 1; return (*this);}
        ReverseConstIterator   operator++(int i)
        {
            if (!i)
                i = 1;
            ReverseConstIterator n(*this);
            this->_ptr -= i;
            return (n);
        }
        ReverseConstIterator   operator--() {this->_ptr += 1; return (*this);}
        ReverseConstIterator   operator--(int i)
        {
            if (!i)
                i = 1;
            ReverseConstIterator n(*this);
            this->_ptr += i;
            return (n);
        }

        ReverseConstIterator operator+(int n) {this->_ptr -= n ; return (*this);}
        ReverseConstIterator operator-(int n) {this->_ptr += n ; return (*this);}

        ReverseConstIterator operator+=(int n) {this->_ptr -= n; return (*this);}
        ReverseConstIterator operator-=(int n) {this->_ptr += n; return (*this);}   
};

}