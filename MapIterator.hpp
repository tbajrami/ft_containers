/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbajrami <tbajrami@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:35:17 by tbajrami          #+#    #+#             */
/*   Updated: 2021/04/23 09:57:11 by tbajrami         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "MapNode.hpp"

namespace ft
{
template<class T>
class MIterator
{
    public:
        
        typedef T value_type;
        typedef MapNode<value_type> Node;

    private:

        Node *_ptr;
        Node *_index;

    public:

    /* canonical functions */

        MIterator() : _ptr(NULL) {}
        virtual ~MIterator() {}
        MIterator &operator=(const MIterator &rhs) {this->_ptr = rhs._ptr ; return *this;}
        MIterator(const MIterator &ref) : _ptr(ref._ptr) {}
        void setPtr(Node *ptr) {this->_ptr = ptr;}
        void setId(Node *ptr) {this->_index = ptr;}
        Node *getPtr() {return this->_ptr;}

    /* operators */

        bool operator==(const MIterator &rhs) const {return (this->_ptr == rhs._ptr);}
        bool operator!=(const MIterator &rhs) const {return (this->_ptr != rhs._ptr);}
        
        value_type &operator*() const {return this->_ptr->elem;}
        value_type *operator->() {return &(this->_ptr->elem);}

        MIterator   operator++()
        {
            if (_ptr == NULL);
            else if (_ptr->right != NULL)
            {
                _ptr = _ptr->right;
                while (_ptr->left != NULL)
                    _ptr = _ptr->left;
            }
            else
            {
                Node *p = _ptr->parent;
                while (p != NULL && _ptr == p->right)
                {
                    _ptr = p;
                    p = p->parent;
                }
                _ptr = p;
            }
            return (*this);
        }

        MIterator   operator++(int i)
        {
            MIterator n(*this);
            if (!i)
                i = 1;
            if (_ptr == NULL);
            else if (_ptr->right != NULL)
            {
                _ptr = _ptr->right;
                while (_ptr->left != NULL)
                    _ptr = _ptr->left;
            }
            else
            {
                Node *p = _ptr->parent;
                while (p != NULL && _ptr == p->right)
                {
                    _ptr = p;
                    p = p->parent;
                }
                _ptr = p;
            }
            return (n);
        }
        MIterator   operator--()
        {
            if (_ptr == NULL)
                setPtr(_index);
            else if (_ptr->left != NULL)
            {
                _ptr = _ptr->left;
                while (_ptr->right != NULL)
                    _ptr = _ptr->left;
            }
            else
            {
                Node *p = _ptr->parent;
                while (p != NULL && _ptr == p->left)
                {
                    _ptr = p;
                    p = p->parent;
                }
                _ptr = p;
            }
            return (*this);
        }
        
        MIterator   operator--(int i)
        {
            MIterator n(*this);
            if (!i)
                i = 1;
            if (_ptr == NULL)
                setPtr(_index);
            else if (_ptr->left != NULL)
            {
                _ptr = _ptr->left;
                while (_ptr->right != NULL)
                    _ptr = _ptr->left;
            }
            else
            {
                Node *p = _ptr->parent;
                while (p != NULL && _ptr == p->left)
                {
                    _ptr = p;
                    p = p->parent;
                }
                _ptr = p;
            }
            return (n);
        }
};

template<class T>
class MConstIterator
{
    public:
        
        typedef T value_type;
        typedef MapNode<value_type> Node;

    private:

        Node *_ptr;
        Node *_index;

    public:

    /* canonical functions */

        MConstIterator() : _ptr(NULL) {}
        virtual ~MConstIterator() {}
        MConstIterator &operator=(const MConstIterator &rhs) {this->_ptr = rhs._ptr ; return *this;}
        MConstIterator(const MConstIterator &ref) : _ptr(ref._ptr) {}
        void setPtr(Node *ptr) {this->_ptr = ptr;}
        void setId(Node *ptr) {this->_index = ptr;}
        Node *getPtr() {return this->_ptr;}

    /* operators */

        bool operator==(const MConstIterator &rhs) const {return (this->_ptr == rhs._ptr);}
        bool operator!=(const MConstIterator &rhs) const {return (this->_ptr != rhs._ptr);}
        
        const value_type &operator*() const {return this->_ptr->elem;}
        const value_type *operator->() const {return &(this->_ptr->elem);}

        MConstIterator   operator++()
        {
            if (_ptr == NULL);
            else if (_ptr->right != NULL)
            {
                _ptr = _ptr->right;
                while (_ptr->left != NULL)
                    _ptr = _ptr->left;
            }
            else
            {
                Node *p = _ptr->parent;
                while (p != NULL && _ptr == p->right)
                {
                    _ptr = p;
                    p = p->parent;
                }
                _ptr = p;
            }
            return (*this);
        }

        MConstIterator   operator++(int i)
        {
            MConstIterator n(*this);
            if (!i)
                i = 1;
            if (_ptr == NULL);
            else if (_ptr->right != NULL)
            {
                _ptr = _ptr->right;
                while (_ptr->left != NULL)
                    _ptr = _ptr->left;
            }
            else
            {
                Node *p = _ptr->parent;
                while (p != NULL && _ptr == p->right)
                {
                    _ptr = p;
                    p = p->parent;
                }
                _ptr = p;
            }
            return (n);
        }
        MConstIterator   operator--()
        {
            if (_ptr == NULL)
                setPtr(_index);
            else if (_ptr->left != NULL)
            {
                _ptr = _ptr->left;
                while (_ptr->right != NULL)
                    _ptr = _ptr->left;
            }
            else
            {
                Node *p = _ptr->parent;
                while (p != NULL && _ptr == p->left)
                {
                    _ptr = p;
                    p = p->parent;
                }
                _ptr = p;
            }
            return (*this);
        }
        
        MConstIterator   operator--(int i)
        {
            MConstIterator n(*this);
            if (!i)
                i = 1;
            if (_ptr == NULL)
                setPtr(_index);
            else if (_ptr->left != NULL)
            {
                _ptr = _ptr->left;
                while (_ptr->right != NULL)
                    _ptr = _ptr->left;
            }
            else
            {
                Node *p = _ptr->parent;
                while (p != NULL && _ptr == p->left)
                {
                    _ptr = p;
                    p = p->parent;
                }
                _ptr = p;
            }
            return (n);
        }
};

template<class T>
class MReverseIterator
{
    public:
        
        typedef T value_type;
        typedef MapNode<value_type> Node;

    private:

        Node *_ptr;
        Node *_index;

    public:

    /* canonical functions */

        MReverseIterator() : _ptr(NULL) {}
        virtual ~MReverseIterator() {}
        MReverseIterator &operator=(const MReverseIterator &rhs) {this->_ptr = rhs._ptr ; return *this;}
        MReverseIterator(const MReverseIterator &ref) : _ptr(ref._ptr) {}
        void setPtr(Node *ptr) {this->_ptr = ptr;}
        void setId(Node *ptr) {this->_index = ptr;}
        Node *getPtr() {return this->_ptr;}

    /* operators */

        bool operator==(const MReverseIterator &rhs) const {return (this->_ptr == rhs._ptr);}
        bool operator!=(const MReverseIterator &rhs) const {return (this->_ptr != rhs._ptr);}
        
        value_type &operator*() const {return this->_ptr->elem;}
        value_type *operator->() {return &(this->_ptr->elem);}

        MReverseIterator   operator--()
        {
            if (_ptr == NULL)
                setPtr(_index);
            else if (_ptr->right != NULL)
            {
                _ptr = _ptr->right;
                while (_ptr->left != NULL)
                    _ptr = _ptr->left;
            }
            else
            {
                Node *p = _ptr->parent;
                while (p != NULL && _ptr == p->right)
                {
                    _ptr = p;
                    p = p->parent;
                }
                _ptr = p;
            }
            return (*this);
        }

        MReverseIterator   operator--(int i)
        {
            MReverseIterator n(*this);
            if (!i)
                i = 1;
            if (_ptr == NULL)
                setPtr(_index);
            else if (_ptr->right != NULL)
            {
                _ptr = _ptr->right;
                while (_ptr->left != NULL)
                    _ptr = _ptr->left;
            }
            else
            {
                Node *p = _ptr->parent;
                while (p != NULL && _ptr == p->right)
                {
                    _ptr = p;
                    p = p->parent;
                }
                _ptr = p;
            }
            return (n);
        }
        MReverseIterator   operator++()
        {
            if (_ptr == NULL);
            else if (_ptr->left != NULL)
            {
                _ptr = _ptr->left;
                while (_ptr->right != NULL)
                    _ptr = _ptr->left;
            }
            else
            {
                Node *p = _ptr->parent;
                while (p != NULL && _ptr == p->left)
                {
                    _ptr = p;
                    p = p->parent;
                }
                _ptr = p;
            }
            return (*this);
        }
        
        MReverseIterator   operator++(int i)
        {
            MReverseIterator n(*this);
            if (!i)
                i = 1;
            if (_ptr == NULL);
            else if (_ptr->left != NULL)
            {
                _ptr = _ptr->left;
                while (_ptr->right != NULL)
                    _ptr = _ptr->left;
            }
            else
            {
                Node *p = _ptr->parent;
                while (p != NULL && _ptr == p->left)
                {
                    _ptr = p;
                    p = p->parent;
                }
                _ptr = p;
            }
            return (n);
        }
};

template<class T>
class MConstReverseIterator
{
    public:
        
        typedef T value_type;
        typedef MapNode<value_type> Node;

    private:

        Node *_ptr;
        Node *_index;

    public:

    /* canonical functions */

        MConstReverseIterator() : _ptr(NULL) {}
        virtual ~MConstReverseIterator() {}
        MConstReverseIterator &operator=(const MConstReverseIterator &rhs) {this->_ptr = rhs._ptr ; return *this;}
        MConstReverseIterator(const MConstReverseIterator &ref) : _ptr(ref._ptr) {}
        void setPtr(Node *ptr) {this->_ptr = ptr;}
        void setId(Node *ptr) {this->_index = ptr;}
        Node *getPtr() {return this->_ptr;}

    /* operators */

        bool operator==(const MConstReverseIterator &rhs) const {return (this->_ptr == rhs._ptr);}
        bool operator!=(const MConstReverseIterator &rhs) const {return (this->_ptr != rhs._ptr);}
        
        value_type &operator*() const {return this->_ptr->elem;}
        const value_type *operator->() const {return &(this->_ptr->elem);}

        MConstReverseIterator   operator--()
        {
            if (_ptr == NULL)
                setPtr(_index);
            else if (_ptr->right != NULL)
            {
                _ptr = _ptr->right;
                while (_ptr->left != NULL)
                    _ptr = _ptr->left;
            }
            else
            {
                Node *p = _ptr->parent;
                while (p != NULL && _ptr == p->right)
                {
                    _ptr = p;
                    p = p->parent;
                }
                _ptr = p;
            }
            return (*this);
        }

        MConstReverseIterator   operator--(int i)
        {
            MConstReverseIterator n(*this);
            if (!i)
                i = 1;
            if (_ptr == NULL)
                setPtr(_index);
            else if (_ptr->right != NULL)
            {
                _ptr = _ptr->right;
                while (_ptr->left != NULL)
                    _ptr = _ptr->left;
            }
            else
            {
                Node *p = _ptr->parent;
                while (p != NULL && _ptr == p->right)
                {
                    _ptr = p;
                    p = p->parent;
                }
                _ptr = p;
            }
            return (n);
        }
        MConstReverseIterator   operator++()
        {
            if (_ptr == NULL);
            else if (_ptr->left != NULL)
            {
                _ptr = _ptr->left;
                while (_ptr->right != NULL)
                    _ptr = _ptr->left;
            }
            else
            {
                Node *p = _ptr->parent;
                while (p != NULL && _ptr == p->left)
                {
                    _ptr = p;
                    p = p->parent;
                }
                _ptr = p;
            }
            return (*this);
        }
        
        MConstReverseIterator   operator++(int i)
        {
            MConstReverseIterator n(*this);
            if (!i)
                i = 1;
            if (_ptr == NULL);
            else if (_ptr->left != NULL)
            {
                _ptr = _ptr->left;
                while (_ptr->right != NULL)
                    _ptr = _ptr->left;
            }
            else
            {
                Node *p = _ptr->parent;
                while (p != NULL && _ptr == p->left)
                {
                    _ptr = p;
                    p = p->parent;
                }
                _ptr = p;
            }
            return (n);
        }
};

}