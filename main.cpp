/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbajrami <tbajrami@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 08:34:32 by tbajrami          #+#    #+#             */
/*   Updated: 2021/03/02 12:30:23 by tbajrami         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include <vector>

int main()
{
    std::vector<int> c(10, 0);
    ft::Vector<int> b(10, 0);

    for (size_t i = 0 ; i < b.size() ; i++)
        b.at(i) = i + 1;
    for (size_t j = 0 ; j < c.size() ; j++)
        c.at(j) = j + 1;
        
    std::cout << "ft::Vector: ";
    for (size_t i = 0 ; i < b.size() ; i++)
        std::cout << ' ' << b.at(i);
    std::cout << '\n';

    std::cout << "std::vector: ";
    for (size_t i = 0 ; i < c.size() ; i++)
        std::cout << ' ' << c.at(i);
    std::cout << '\n';

    b.resize(5);
    b.resize(8,100);
    b.resize(12);

    c.resize(5);
    c.resize(8,100);
    c.resize(12);

    std::cout << "ft::Vector: ";
    for (size_t i = 0 ; i < b.size() ; i++)
        std::cout << ' ' << b.at(i);
    std::cout << '\n';

    std::cout << "std::vector: ";
    for (size_t i = 0 ; i < c.size() ; i++)
        std::cout << ' ' << c.at(i);
    std::cout << '\n';
    
    std::cout << "\nft vector size: " << b.size() << std::endl;
    std::cout << "std vector size: " << c.size() << std::endl;
    
    std::cout << "\nft vector max_size: " << b.max_size() << std::endl;
    std::cout << "std vector max_size: " << c.max_size() << std::endl;

    std::cout << "\nft vector capacity: " << b.capacity() << std::endl;
    std::cout << "std vector capacity: " << c.capacity() << std::endl;
}