/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbajrami <tbajrami@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:04:49 by tbajrami          #+#    #+#             */
/*   Updated: 2021/04/21 16:22:32 by tbajrami         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <functional>
#include <utility>
#include <map>
#include "MapNode.hpp"
#include "MapIterator.hpp"

namespace ft
{

template <class Key, class T, class Compare = std::less<Key> >
class Map
{
public:

    typedef std::pair<const Key, T>             value_type;
    typedef T                                   mapped_type;
    typedef Key                                 key_type;
    typedef size_t                              size_type;
    typedef Compare                             key_compare;
    typedef MIterator<value_type>               iterator;
    typedef MConstIterator<value_type>          const_iterator;
    typedef MReverseIterator<value_type>        reverse_iterator;
    typedef MConstReverseIterator<value_type>   const_reverse_iterator;
    typedef MapNode<value_type>                 Node;

private:

    size_type _size;

protected:

    Node *_root;

public:

    explicit Map() : _size(0), _root(NULL) {}

    template <class InputIterator>
    Map(InputIterator first, InputIterator last)
    {
        iterator it;

        for (it = first ; it != last ; it++)
            this->insert((*it));
    }

    Map(const Map &x)
    {
        const_iterator it;

        for (it = x.begin() ; it != x.end() ; it++)
            this->insert((*it));
    }

    bool empty() const {return !_size;}
    size_type size() {return _size;}
    size_type max_size() {return (std::numeric_limits<size_type>::max() / sizeof(value_type));}

    iterator begin()
    {
        iterator it;
        Node *temp = _root;

        while (temp->left)
            temp = temp->left;
        it.setPtr(temp);
        return it;
    }

    iterator end()
    {
        iterator it;
        Node *temp = _root;

        it.setPtr(NULL);
        while (temp->right)
            temp = temp->right;
        it.setId(temp);
        return it;
    }

    const_iterator begin() const
    {
        const_iterator it;
        Node *temp = _root;

        while (temp->left)
            temp = temp->left;
        it.setPtr(temp);
        return it;
    }

    const_iterator end() const
    {
        const_iterator it;
        Node *temp = _root;

        it.setPtr(NULL);
        while (temp->right)
            temp = temp->right;
        it.setId(temp);
        return it;
    }

    reverse_iterator rbegin()
    {
        reverse_iterator it;
        Node *temp = _root;

        while (temp->right)
            temp = temp->right;
        it.setPtr(temp);
        return it;
    }

    reverse_iterator rend()
    {
        reverse_iterator it;
        Node *temp = _root;

        it.setPtr(NULL);
        while (temp->left)
            temp = temp->left;
        it.setId(temp);
        return it;
    }

    const_reverse_iterator rbegin() const
    {
        const_reverse_iterator it;
        Node *temp = _root;

        while (temp->right)
            temp = temp->right;
        it.setPtr(temp);
        return it;
    }

    const_reverse_iterator rend() const
    {
        const_reverse_iterator it;
        Node *temp = _root;

        it.setPtr(NULL);
        while (temp->left)
            temp = temp->left;
        it.setId(temp);
        return it;
    }

    std::pair<iterator, bool>   insert(const value_type &val)
    {
        iterator it;
        key_compare c;

        if (!_root)
            _root = node_init(val);
        else if (exist_key(val))
        {
            it = begin();
            while ((*it).first != val.first)
                it++;
            return std::pair<iterator, bool>(it, false);
        }
        else
        {
            Node *tmpNode;
            Node *tmpTree = _root;
            Node *newnode;
            newnode = node_init(val);
            do
            {
                tmpNode = tmpTree;
                if (c(tmpTree->elem.first, val.first))
                {
                    tmpTree = tmpTree->right;
                    if (!tmpTree)
                    {
                        tmpNode->right = newnode;
                        newnode->parent = tmpNode;
                    }
                }
                else
                {
                    tmpTree = tmpTree->left;
                    if (!tmpTree)
                    {
                        tmpNode->left = newnode;
                        newnode->parent = tmpNode;
                    }
                }
            } while (tmpTree);
        }
        it = begin();
        while ((*it).first != val.first)
            it++;
        return std::pair<iterator, bool>(it, true);
    }

private:

    Node *node_init(const value_type &val)
    {
        Node *t = new Node(val);
        t->parent = NULL;
        t->right = NULL;
        t->left = NULL;
        return (t);
    }

    bool exist_key(const value_type &val)
    {
        iterator it = begin();

        while (it != end())
        {
            if ((*it).first == val.first)
                return true;
            it++;
        }
        return false;
    }
};

}