/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BidirectionalIterator.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbajrami <tbajrami@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 14:57:05 by tbajrami          #+#    #+#             */
/*   Updated: 2021/04/23 09:58:07 by tbajrami         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Node.hpp"

namespace ft
{
template<class T>
class BIterator
{
    public:
        
        typedef T value_type;

    private:

        Node<value_type> *_ptr;

    public:

    /* canonical functions */

        BIterator() : _ptr(NULL) {}
        virtual ~BIterator() {}
        BIterator &operator=(const BIterator &rhs) {this->_ptr = rhs._ptr ; return *this;}
        BIterator(const BIterator &ref) : _ptr(ref._ptr) {}
        void setPtr(Node<value_type> *ptr) {this->_ptr = ptr;}

    /* operators */

        bool operator==(const BIterator &rhs) const {return (this->_ptr == rhs._ptr);}
        bool operator!=(const BIterator &rhs) const {return (this->_ptr != rhs._ptr);}
        
        value_type &operator*() const {return this->_ptr->elem;}
        value_type *operator->() {return &(this->_ptr->elem);}

        BIterator   operator++() {this->_ptr = this->_ptr->next; return (*this);}
        BIterator   operator++(int i)
        {
            if (!i)
                i = 1;
            BIterator n(*this);
            this->_ptr = this->_ptr->next;
            return (n);
        }
        BIterator   operator--() {this->_ptr = this->_ptr->prev; return (*this);}
        BIterator   operator--(int i)
        {
            if (!i)
                i = 1;
            BIterator n(*this);
            this->_ptr = this->_ptr->prev;
            return (n);
        }
};

template <class T>
class BReverseIterator
{
    public:
        
        typedef T value_type;

    private:

        Node<value_type> *_ptr;

    public:

    /* canonical functions */

        BReverseIterator() : _ptr(NULL) {}
        virtual ~BReverseIterator() {}
        BReverseIterator &operator=(const BReverseIterator &rhs) {this->_ptr = rhs._ptr ; return *this;}
        BReverseIterator(const BReverseIterator &ref) : _ptr(ref._ptr) {}
        void setPtr(Node<value_type> *ptr) {this->_ptr = ptr;}

    /* operators */

        bool operator==(const BReverseIterator &rhs) const {return (this->_ptr == rhs._ptr);}
        bool operator!=(const BReverseIterator &rhs) const {return (this->_ptr != rhs._ptr);}
        
        value_type &operator*() const {return this->_ptr->elem;}
        value_type *operator->() {return &(this->_ptr->elem);}

        BReverseIterator   operator++() {this->_ptr = this->_ptr->prev; return (*this);}
        BReverseIterator   operator++(int i)
        {
            if (!i)
                i = 1;
            BReverseIterator n(*this);
            this->_ptr = this->_ptr->prev;
            return (n);
        }
        BReverseIterator   operator--() {this->_ptr = this->_ptr->next; return (*this);}
        BReverseIterator   operator--(int i)
        {
            if (!i)
                i = 1;
            BReverseIterator n(*this);
            this->_ptr = this->_ptr->next;
            return (n);
        }
};

template <class T>
class BConstIterator
{
    public:
        
        typedef T value_type;

    private:

        Node<value_type> *_ptr;

    public:

    /* canonical functions */

        BConstIterator() : _ptr(NULL) {}
        virtual ~BConstIterator() {}
        BConstIterator &operator=(const BConstIterator &rhs) {this->_ptr = rhs._ptr ; return *this;}
        BConstIterator(const BConstIterator &ref) : _ptr(ref._ptr) {}
        void setPtr(Node<value_type> *ptr) {this->_ptr = ptr;}

    /* operators */

        bool operator==(const BConstIterator &rhs) const {return (this->_ptr == rhs._ptr);}
        bool operator!=(const BConstIterator &rhs) const {return (this->_ptr != rhs._ptr);}
        
        const value_type &operator*() const {return this->_ptr->elem;}
        const value_type *operator->() const {return &(this->_ptr->elem);}

        BConstIterator   operator++() {this->_ptr = this->_ptr->next; return (*this);}
        BConstIterator   operator++(int i)
        {
            if (!i)
                i = 1;
            BConstIterator n(*this);
            this->_ptr = this->_ptr->next;
            return (n);
        }
        BConstIterator   operator--() {this->_ptr = this->_ptr->prev; return (*this);}
        BConstIterator   operator--(int i)
        {
            if (!i)
                i = 1;
            BConstIterator n(*this);
            this->_ptr = this->_ptr->prev;
            return (n);
        }
};

template <class T>
class BReverseConstIterator
{
    public:

        typedef T value_type;

    private:

        Node<value_type> *_ptr;

    public:

    /* canonical functions */

        BReverseConstIterator() : _ptr(NULL) {}
        virtual ~BReverseConstIterator() {}
        BReverseConstIterator &operator=(const BReverseConstIterator &rhs) {this->_ptr = rhs._ptr ; return *this;}
        BReverseConstIterator(const BReverseConstIterator &ref) : _ptr(ref._ptr) {}
        void setPtr(Node<value_type> *ptr) {this->_ptr = ptr;}

    /* operators */

        bool operator==(const BReverseConstIterator &rhs) const {return (this->_ptr == rhs._ptr);}
        bool operator!=(const BReverseConstIterator &rhs) const {return (this->_ptr != rhs._ptr);}
        
        const value_type &operator*() const {return this->_ptr->elem;}
        const value_type *operator->() const {return &(this->_ptr->elem);}

        BReverseConstIterator   operator++() {this->_ptr = this->_ptr->prev; return (*this);}
        BReverseConstIterator   operator++(int i)
        {
            if (!i)
                i = 1;
            BReverseConstIterator n(*this);
            this->_ptr = this->_ptr->prev;
            return (n);
        }
        BReverseConstIterator   operator--() {this->_ptr = this->_ptr->next; return (*this);}
        BReverseConstIterator   operator--(int i)
        {
            if (!i)
                i = 1;
            BReverseConstIterator n(*this);
            this->_ptr = this->_ptr->next;
            return (n);
        }
};

}