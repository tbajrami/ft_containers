/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapNode.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbajrami <tbajrami@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:48:33 by tbajrami          #+#    #+#             */
/*   Updated: 2021/04/21 14:36:18 by tbajrami         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */



#pragma once

namespace ft
{
template<class T>
struct MapNode
{
    T          elem;
    MapNode    *left;
    MapNode    *right;
    MapNode    *parent;

    MapNode(T elem) : elem(elem) {}
};
}