/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbajrami <tbajrami@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 08:34:32 by tbajrami          #+#    #+#             */
/*   Updated: 2021/03/04 13:35:53 by tbajrami         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include <vector>
#include <list>

int main()
{
    std::vector<int> c(10, 0);
    ft::Vector<int> b(10, 0);

    std::cout << "\n######### --------- VECTOR --------- #########\n\n";
    std::cout << "\n##### ----- SIZE FUNCTIONS ----- #####\n";

    std::cout << "\n### --- vector(10, 0) then assign value 1 to 10 --- ###\n";

    for (size_t i = 0 ; i < b.size() ; i++)
        b.at(i) = i + 1;
    for (size_t j = 0 ; j < c.size() ; j++)
        c.at(j) = j + 1;

    std::cout << "\nft vector size: " << b.size() << std::endl;
    std::cout << "sd vector size: " << c.size() << std::endl;

    std::cout << "\nft vector capacity: " << b.capacity() << std::endl;
    std::cout << "sd vector capacity: " << c.capacity() << std::endl;

    std::cout << "\nft vector: ";
    for (size_t i = 0 ; i < b.size() ; i++)
        std::cout << ' ' << b.at(i);
    std::cout << '\n';

    std::cout << "sd vector: ";
    for (size_t i = 0 ; i < c.size() ; i++)
        std::cout << ' ' << c.at(i);
    std::cout << '\n';

    std::cout << "\n### --- resize(5) --- ###\n";

    b.resize(5);
    c.resize(5);

    std::cout << "\nft vector size: " << b.size() << std::endl;
    std::cout << "sd vector size: " << c.size() << std::endl;

    std::cout << "\nft vector capacity: " << b.capacity() << std::endl;
    std::cout << "sd vector capacity: " << c.capacity() << std::endl;

    std::cout << "\nft vector: ";
    for (size_t i = 0 ; i < b.size() ; i++)
        std::cout << ' ' << b.at(i);
    std::cout << '\n';

    std::cout << "sd vector: ";
    for (size_t i = 0 ; i < c.size() ; i++)
        std::cout << ' ' << c.at(i);
    std::cout << '\n';
    
    std::cout << "\n### --- resize(8, 100) --- ###\n";

    b.resize(8,100);
    c.resize(8,100);

    std::cout << "\nft vector size: " << b.size() << std::endl;
    std::cout << "sd vector size: " << c.size() << std::endl;

    std::cout << "\nft vector capacity: " << b.capacity() << std::endl;
    std::cout << "sd vector capacity: " << c.capacity() << std::endl;
    
    std::cout << "\nft vector: ";
    for (size_t i = 0 ; i < b.size() ; i++)
        std::cout << ' ' << b.at(i);
    std::cout << '\n';

    std::cout << "sd vector: ";
    for (size_t i = 0 ; i < c.size() ; i++)
        std::cout << ' ' << c.at(i);
    std::cout << '\n';
    
    std::cout << "\n### --- resize(12) --- ###\n";

    b.resize(12);
    c.resize(12);

    std::cout << "\nft vector size: " << b.size() << std::endl;
    std::cout << "sd vector size: " << c.size() << std::endl;

    std::cout << "\nft vector capacity: " << b.capacity() << std::endl;
    std::cout << "sd vector capacity: " << c.capacity() << std::endl;

    std::cout << "\nft vector: ";
    for (size_t i = 0 ; i < b.size() ; i++)
        std::cout << ' ' << b.at(i);
    std::cout << '\n';

    std::cout << "sd vector: ";
    for (size_t i = 0 ; i < c.size() ; i++)
        std::cout << ' ' << c.at(i);
    std::cout << '\n';

    std::cout << "\n### --- max size --- ###\n";
    
    std::cout << "\nft vector max_size: " << b.max_size() << std::endl;
    std::cout << "sd vector max_size: " << c.max_size() << std::endl;

    std::cout << "\n### --- empty ? --- ###\n";

    std::cout << "\nprevious vectors :";
    std::cout << "\nft vector empty ? " << b.empty() << std::endl;
    std::cout << "sd vector empty ? " << c.empty() << std::endl;

    ft::Vector<int> d;
    std::vector<int> e;
    
    std::cout << "\nnew vectors without parameters :\n";
    std::cout << "ft vector empty ? " << d.empty() << std::endl;
    std::cout << "sd vector empty ? " << e.empty() << std::endl;

    std::cout << "\n### --- reserve(10) --- ###\n";

    b.reserve(10);
    c.reserve(10);

    std::cout << "\nft vector size: " << b.size() << std::endl;
    std::cout << "sd vector size: " << c.size() << std::endl;
    
    std::cout << "\nft vector capacity: " << b.capacity() << std::endl;
    std::cout << "sd vector capacity: " << c.capacity() << std::endl;

    std::cout << "\n### --- reserve(42) --- ###\n";

    b.reserve(42);
    c.reserve(42);

    std::cout << "\nft vector size: " << b.size() << std::endl;
    std::cout << "sd vector size: " << c.size() << std::endl;

    std::cout << "\nft vector capacity: " << b.capacity() << std::endl;
    std::cout << "sd vector capacity: " << c.capacity() << std::endl;

    std::cout << "\n### --- resize(100) --- ###\n";

    b.resize(100);
    c.resize(100);

    std::cout << "\nft vector size: " << b.size() << std::endl;
    std::cout << "sd vector size: " << c.size() << std::endl;

    std::cout << "\nft vector capacity: " << b.capacity() << std::endl;
    std::cout << "sd vector capacity: " << c.capacity() << std::endl;
}