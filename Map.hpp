/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbajrami <tbajrami@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:04:49 by tbajrami          #+#    #+#             */
/*   Updated: 2021/04/15 12:19:04 by tbajrami         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <functional>
#include <utility>
#include <map>

namespace ft
{

template <class Key, class T, class Compare = less<Key> >
class Map
{
public:

    typedef pair<const Key, T>  value_type;
    typedef T                   mapped_type;
    typedef Key                 key_type;
    typedef size_t              size_type;


};

}