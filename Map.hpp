/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbajrami <tbajrami@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:04:49 by tbajrami          #+#    #+#             */
/*   Updated: 2021/04/22 17:36:18 by tbajrami         ###   ########lyon.fr   */
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

	class value_compare : public std::binary_function<value_type,value_type,bool>
	{
		friend class Map;
		protected:
			Compare comp;
			value_compare (Compare c) : comp(c) {}
		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;

			bool operator() (const value_type& x, const value_type& y) const
			{return comp(x.first, y.first);}
	};

private:

	size_type _size;

protected:

	Node *_root;

public:

	/* CONSTRUCTORS // DESTRUCTOR */

	explicit Map() : _size(0), _root(NULL) {}

	template <class InputIterator>
	Map(InputIterator first, InputIterator last) : _size(0), _root(NULL)
	{
		iterator it;

		for (it = first ; it != last ; it++)
			this->insert((*it));
	}

	Map(const Map &x) : _size(0), _root(NULL)
	{
		const_iterator it;

		for (it = x.begin() ; it != x.end() ; it++)
			this->insert((*it));
	}

	Map &operator=(const Map &x)
	{
		const_iterator it;

		clear();
		for (it = x.begin() ; it != x.end() ; it++)
			this->insert((*it));
		return (*this);
	}

	~Map() {clear();}

	/* CAPACITY */

	bool empty() const {return !_size;}
	size_type size() {return _size;}
	size_type max_size() {return (std::numeric_limits<size_type>::max() / sizeof(value_type));}

	/* ITERATORS */

	iterator begin()
	{
		iterator it;
		Node *temp = _root;

		if (!_size)
			it.setPtr(_root);
		else while (temp->left)
			temp = temp->left;
		it.setPtr(temp);
		return it;
	}

	iterator end()
	{
		iterator it;
		Node *temp = _root;

		if (!_size)
			it.setPtr(_root);
		else while (temp->right)
			temp = temp->right;
		it.setId(temp);
		return it;
	}

	const_iterator begin() const
	{
		const_iterator it;
		Node *temp = _root;

		if (!_size) it.setPtr(_root);
		else while (temp->left)
			temp = temp->left;
		it.setPtr(temp);
		return it;
	}

	const_iterator end() const
	{
		const_iterator it;
		Node *temp = _root;

		if (!_size) it.setPtr(_root);
		else while (temp->right)
			temp = temp->right;
		it.setId(temp);
		return it;
	}

	reverse_iterator rbegin()
	{
		reverse_iterator it;
		Node *temp = _root;

		if (!_size) it.setPtr(_root);
		else while (temp->right)
			temp = temp->right;
		it.setPtr(temp);
		return it;
	}

	reverse_iterator rend()
	{
		reverse_iterator it;
		Node *temp = _root;

		if (!_size) it.setPtr(_root);
		else while (temp->left)
			temp = temp->left;
		it.setId(temp);
		return it;
	}

	const_reverse_iterator rbegin() const
	{
		const_reverse_iterator it;
		Node *temp = _root;

		if (!_size) it.setPtr(_root);
		else while (temp->right)
			temp = temp->right;
		it.setPtr(temp);
		return it;
	}

	const_reverse_iterator rend() const
	{
		const_reverse_iterator it;
		Node *temp = _root;

		if (!_size) it.setPtr(_root);
		else while (temp->left)
			temp = temp->left;
		it.setId(temp);
		return it;
	}

	/* ELEMENT ACCESS */

	mapped_type &operator[](const key_type &k)
	{
		for (iterator it = begin() ; it != end() ; it++)
		{
			if ((*it).first == k)
				return (*it).second;
		}
		const value_type pair(k, mapped_type());
		insert(pair);
		return ((*this)[k]);
	}

	/* MODIFIERS */

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

	iterator	insert(iterator position, const value_type &val)
	{
		key_compare c;
		iterator next = position;

		next++;
		if (!_root)
			_root = node_init(val);
		else if (exist_key(val))
		{
			iterator it;
			it = begin();
			while ((*it).first != val.first)
				it++;
			return it;
		}
		else if (c((*position).first, val.first) && c((val.first), (*next).first))
		{
			Node *tmp = position.getPtr();
			Node *newnode = node_init(val);
			if (!tmp->right)
			{
				tmp->right = newnode;
				newnode->parent = tmp;
			}
			else
			{
				tmp = tmp->right;
				while (tmp->left)
					tmp = tmp->left;
				tmp->left = newnode;
				newnode->parent = tmp;
			}
		}
		position++;
		return position;
	}

	template<class InputIterator>
	void insert(InputIterator first, InputIterator last)
	{
		iterator it;
		for (it = first ; it != last ; it++)
			insert((*it));
	}

	void erase(iterator position)
	{
		Node *tmp = position.getPtr();

		if (!tmp || !_size) return;
		if (_size == 1 && position == begin())
		{
			delete tmp;
			tmp = NULL;
			_root = NULL;
		}
		else if (!tmp->right && !tmp->left)
			erase_leaf(tmp);
		else if ((!tmp->right && tmp->left) || (tmp->right && !tmp->left))
			erase_onechild(tmp);
		else if (tmp->right && tmp->left)
			erase_two(tmp, position);
		_size -= 1;
	}

	size_type erase(const key_type &k)
	{
		for (iterator it = begin() ; it != end() ; it++)
		{
			if ((*it).first == k)
			{
				erase(it);
				return 1;
			}
		}
		return 0;
	}

	void erase(iterator first, iterator last)
	{
		iterator tmp;

		while (first != last)
		{
			tmp = first;
			tmp++;
			erase(first);
			first = tmp;
		}
	}

	void swap(Map &x)
	{
		std::swap(_root, x._root);
		std::swap(_size, x._size);
	}

	void clear()
	{
		erase(begin(), end());
	}

	key_compare key_comp() const
	{
		key_compare k;
		return k;
	}

	value_compare value_comp() const
	{
		Compare c;
		value_compare k(c);
		return k;
	}

	iterator find(const key_type &k)
	{
		for (iterator it = begin() ; it != end() ; it++)
		{
			if ((*it).first == k)
				return it;
		}
		return end();
	}

	const_iterator find(const key_type &k) const
	{
		for (const_iterator it = begin() ; it != end() ; it++)
		{
			if ((*it).first == k)
				return it;
		}
		return end();
	}

	size_type count(const key_type &k) const
	{
		if (find(k) == end())
			return 0;
		return 1;
	}

	iterator lower_bound(const key_type &k)
	{
		iterator it;
		key_compare c;

		for (it = begin() ; it != end() ; it++)
		{
			if (c((*it).first, k) == false)
				return it;
		}
		return it;
	}

	const_iterator lower_bound(const key_type &k) const
	{
		const_iterator it;
		key_compare c;

		for (it = begin() ; it != end() ; it++)
		{
			if (c((*it).first, k) == false)
				return it;
		}
		return it;
	}

	iterator upper_bound(const key_type &k)
	{
		iterator it;
		key_compare c;

		for (it = begin() ; it != end() ; it++)
		{
			if (c(k, (*it).first) == true)
				return it;
		}
		return it;
	}

	const_iterator upper_bound(const key_type &k) const
	{
		const_iterator it;
		key_compare c;

		for (it = begin() ; it != end() ; it++)
		{
			if (c(k, (*it).first) == true)
				return it;
		}
		return it;
	}

private:

	Node *node_init(const value_type &val)
	{
		Node *t = new Node(val);
		_size++;
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

	void erase_leaf(Node *tmp)
	{
		Node *tmp2 = tmp;
		tmp = tmp->parent;
		if (tmp->right == tmp2)
		{
			delete tmp->right;
			tmp->right = NULL;
		}
		else
		{
			delete tmp->left;
			tmp->left = NULL;
		}
	}

	void erase_onechild(Node *tmp)
	{
		if (!tmp->right && tmp->left)
		{
			if (tmp == _root)
				_root = tmp->left;
			Node *tmp3 = tmp->left;
			tmp3->right = tmp->right;
			tmp3->parent = tmp->parent;
			if (tmp3->right != _root)
				tmp3->parent->left = tmp3;
			delete tmp;
		}
		else if (tmp->right && !tmp->left)
		{
			if (tmp == _root)
				_root = tmp->right;
			Node *tmp3 = tmp->right;
			tmp3->left = tmp->left;
			tmp3->parent = tmp->parent;
			if (tmp->right != _root)
				tmp3->parent->right = tmp3;
			delete tmp;
		}
	}

	void erase_two(Node *tmp, iterator position)
	{
		iterator pos2 = position;
		pos2++;
		Node *tmp3 = pos2.getPtr();
		Node *tmp4 = tmp3->parent;

		if (tmp == _root)
			_root = tmp3;
		if (!tmp3->right && !tmp3->left)
		{
			tmp3->right = tmp->right;
			tmp->right->parent = tmp3;
			tmp4->left = NULL;
		}
		tmp3->left = tmp->left;
		tmp3->parent = tmp->parent;
		if (_root != tmp3)
			tmp3->parent->right = tmp3;
		tmp->left->parent = tmp3;
		delete tmp;
	}
};

}