/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbajrami <tbajrami@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 08:34:32 by tbajrami          #+#    #+#             */
/*   Updated: 2021/04/06 17:16:22 by tbajrami         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include <vector>
#include <list>

int main()
{
    ft::Vector<int> b(10, 0);
    std::vector<int> c(10, 0);

    std::cout << "\n######### --------- VECTOR --------- #########\n\n";
    
    std::cout << "\n######################################";
    std::cout << "\n##### ----- SIZE FUNCTIONS ----- #####";
    std::cout << "\n######################################\n";

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

    std::cout << "\n######################################";
    std::cout << "\n######## ----- ITERATORS ----- #######";
    std::cout << "\n######################################\n";

    std::cout << "\n### --- resize(20) + using iterators --- ###\n";

    b.resize(20);
    c.resize(20);

    for (size_t i = 0 ; i < b.size() ; i++)
        b.at(i) = i + 1;
    for (size_t j = 0 ; j < c.size() ; j++)
        c.at(j) = j + 1;

    std::vector<int>::iterator its;
    ft::Vector<int>::iterator itf;

    std::cout << "\nft vector:\n";
    for (itf = b.begin() ; itf != b.end() ; itf++)
        std::cout << *itf << " ";

    std::cout << "\nsd vector:\n";
    for (its = c.begin() ; its != c.end() ; its++)
        std::cout << *its << " ";
    std::cout << "\n\n";

    std::cout << "end:\n";
    std::cout << *itf << std::endl;
    std::cout << *its << std::endl;

    std::cout << "\n--end:\n";
    std::cout << *(--itf) << std::endl;
    std::cout << *(--its) << std::endl;

    ++itf;
    ++its;

    std::cout << "\nsd begin[5]: " << c.begin()[5] << std::endl;
    std::cout << "ft begin[5]: " << b.begin()[5] << std::endl;

    std::cout << "\n### --- reverse iterators --- ###\n\n";

    std::cout << "sd rbegin: " << *(c.rbegin()) << std::endl;
    std::cout << "ft rbegin: " << *(b.rbegin()) << std::endl << std::endl;

    std::cout << "sd rend : " << *(c.rend()) << std::endl;
    std::cout << "ft rend : " << *(b.rend()) << std::endl << std::endl;

    std::cout << "sd rend - 1: " << *(c.rend() - 1) << std::endl;
    std::cout << "ft rend - 1: " << *(b.rend() - 1) << std::endl << std::endl;

    std::cout << "sd rbegin + 1: " << *(c.rbegin() + 1) << std::endl;
    std::cout << "ft rbegin + 1: " << *(b.rbegin() + 1) << std::endl << std::endl;

    std::cout << "sd rend[5]: " << c.rend()[5] << std::endl;
    std::cout << "ft rend[5]: " << b.rend()[5] << std::endl << std::endl;

    std::cout << "sd rbegin[5]: " << c.rbegin()[5] << std::endl;
    std::cout << "ft rbegin[5]: " << b.rbegin()[5] << std::endl;


    std::cout << "\n### --- overload operators --- ###\n";

    std::vector<int>::iterator its2 = c.end();
    ft::Vector<int>::iterator itf2 = b.end();

    std::cout << "\nend iterators compared to previous operators" << std::endl;
    std::cout << "sd vector: " << (its == its2) << std::endl;
    std::cout << "ft vector: " << (itf == itf2) << std::endl;

    std::cout << "\ndecrement one of them" << std::endl;

    its--;
    itf--;

    std::cout << "sd vector: " << (its == its2) << std::endl;
    std::cout << "ft vector: " << (itf == itf2) << std::endl;

    std::cout << "\nbegin = begin + 5" << std::endl;

    its = c.begin() + 5;
    itf = b.begin() + 5;

    std::cout << "sd vector: " << *its << std::endl;
    std::cout << "ft vector: " << *itf << std::endl;

    std::cout << "\n+=5" << std::endl;

    its += 5;
    itf += 5;

    std::cout << "sd vector: " << *its << std::endl;
    std::cout << "ft vector: " << *itf << std::endl;

    std::cout << "\n-=10" << std::endl;

    its -=10;
    itf -=10;

    std::cout << "sd vector: " << *its << std::endl;
    std::cout << "ft vector: " << *itf << std::endl;

    std::cout << "\n######################################";
    std::cout << "\n####### --- ELEMENT  ACCESS --- ######";
    std::cout << "\n######################################\n";

    std::cout << "\nsd vector at(5): " << c.at(5) << std::endl;
    std::cout << "ft vector at(5): " << b.at(5) << std::endl;

    std::cout << "\nsd vector[5]: " << c[5] << std::endl;
    std::cout << "ft vector[5]: " << b[5] << std::endl;

    std::cout << "\nsd front: " << c.front() << std::endl;
    std::cout << "ft front: " << b.front() << std::endl;

    std::cout << "\nsd back: " << c.back() << std::endl;
    std::cout << "ft back: " << b.back() << std::endl;

    std::cout << "\n######################################";
    std::cout << "\n######## ----- DEEP COPY ----- #######";
    std::cout << "\n######################################\n";

    ft::Vector<int> ft_copy(b);
    ft::Vector<int>::iterator itc;

    std::cout << "\nft vector:\n";
    for (itf = b.begin() ; itf != b.end() ; itf++)
        std::cout << *itf << " ";

    std::cout << "\n\nchange copy[5]: = 0\n";
    ft_copy[5] = 0;
    std::cout << "\ncp vector:\n";
    for (itc = ft_copy.begin() ; itc != ft_copy.end() ; itc++)
        std::cout << *itc << " ";
    std::cout << "\n\n";

    std::cout << "\n######################################";
    std::cout << "\n######## ----- MODIFIERS ----- #######";
    std::cout << "\n######################################\n";

    std::cout << "\n### --- assign (value) --- ###\n\n";

    std::vector<int> std_copy(c);

    std::cout << "\n### --- std --- ###\n\n";

    std::cout << "capacity before assign: " << c.capacity() << std::endl;
    c.assign(7, 100);
    std::cout << "assign(7, 100): ";
    for (its = c.begin() ; its != c.end() ; its++)
        std::cout << *its << " ";
    std::cout << "\ncapacity after assign: " << c.capacity() << std::endl;
    c.assign(300, 5);
    std::cout << "assign(300, 5): ";
    for (its = c.begin() ; its != c.end() ; its++)
        std::cout << *its << " ";
    std::cout << "\ncapacity after assign: " << c.capacity() << std::endl;

    std::cout << "\n### --- ft --- ###\n\n";

    std::cout << "capacity before assign: " << b.capacity() << std::endl;
    b.assign(7, 100);
    std::cout << "assign(7, 100): ";
    for (itf = b.begin() ; itf != b.end() ; itf++)
        std::cout << *itf << " ";
    std::cout << "\ncapacity after assign: " << b.capacity() << std::endl;
    b.assign(300, 5);
    std::cout << "assign(300, 5): ";
    for (itf = b.begin() ; itf != b.end() ; itf++)
        std::cout << *itf << " ";
    std::cout << "\ncapacity after assign: " << b.capacity() << std::endl;

    std::cout << "\n### --- assign (range) --- ###\n\n";
    
    std::cout << "\n### --- std --- ###\n\n";

    c.assign(std_copy.begin(), std_copy.end());
    std::cout << "assign(vec(300) to vec 1-20): ";
    for (its = c.begin() ; its != c.end() ; its++)
        std::cout << *its << " ";
    std::cout << "\ncapacity after assign: " << c.capacity() << std::endl;

    std::vector<int> std5(5, 5);

    std5.assign(c.begin(), c.end());
    std::cout << "\nassign(vec(5) to vec 1-20): ";
    for (its = std5.begin() ; its != std5.end() ; its++)
        std::cout << *its << " ";
    std::cout << "\ncapacity after assign: " << std5.capacity() << std::endl;

    std::cout << "\n### --- ft --- ###\n\n";

    b.assign(ft_copy.begin(), ft_copy.end());
    std::cout << "assign(vec(300) to vec 1-20): ";
    for (itf = b.begin() ; itf != b.end() ; itf++)
        std::cout << *itf << " ";
    std::cout << "\ncapacity after assign: " << b.capacity() << std::endl;

    ft::Vector<int> ft5(5, 5);

    ft5.assign(b.begin(), b.end());
    std::cout << "\nassign(vec(5) to vec 1-20): ";
    for (itf = ft5.begin() ; itf != ft5.end() ; itf++)
        std::cout << *itf << " ";
    std::cout << "\ncapacity after assign: " << ft5.capacity() << std::endl;

    std::cout << "\n### --- assign (reverse iterators) --- ###\n\n";

    std::cout << "\n### --- std --- ###\n\n";

    c.assign(300, 5);

    c.assign(std5.rbegin(), std5.rend());
    std::cout << "assign(vec(300) to vec 1-20): ";
    for (its = c.begin() ; its != c.end() ; its++)
        std::cout << *its << " ";
    std::cout << "\ncapacity after assign: " << c.capacity() << std::endl;

    std5.assign(5, 5);

    std5.assign(c.rbegin(), c.rend());
    std::cout << "\nassign(vec(5) to vec 1-20): ";
    for (its = std5.begin() ; its != std5.end() ; its++)
        std::cout << *its << " ";
    std::cout << "\ncapacity after assign: " << std5.capacity() << std::endl;

    std::cout << "\n### --- ft --- ###\n\n";

    b.assign(300, 5);

    b.assign(ft5.rbegin(), ft5.rend());
    std::cout << "assign(vec(300) to vec 1-20): ";
    for (itf = b.begin() ; itf != b.end() ; itf++)
        std::cout << *itf << " ";
    std::cout << "\ncapacity after assign: " << b.capacity() << std::endl;

    ft5.assign(5, 5);

    ft5.assign(b.rbegin(), b.rend());
    std::cout << "\nassign(vec(5) to vec 1-20): ";
    for (itf = ft5.begin() ; itf != ft5.end() ; itf++)
        std::cout << *itf << " ";
    std::cout << "\ncapacity after assign: " << ft5.capacity() << std::endl;

    std::cout << "\n### --- push_back --- ###\n\n";

    std::cout << "\n### --- std --- ###\n\n";

    std::vector<int> nvec;

    for (size_t i = 0 ; i < 20 ; i++)
    {
        nvec.push_back(i);
        std::cout << "capacity: " << nvec.capacity() << std::endl;
    }
    for (size_t i = 0 ; i < 20 ; i++)
        std::cout << "std[" << i << "]: " << nvec[i] << std::endl;

    std::cout << "\n### --- ft --- ###\n\n";

    ft::Vector<int> fvec;

    for (size_t i = 0 ; i < 20 ; i++)
    {
        fvec.push_back(i);
        std::cout << "capacity: " << fvec.capacity() << std::endl;
    }

    for (size_t i = 0 ; i < 20 ; i++)
        std::cout << "ft[" << i << "]: " << fvec[i] << std::endl;

    nvec.pop_back();
    fvec.pop_back();

    std::cout << "\n### --- 1 pop_back (std then ft) --- ###\n\n";

    for (its = nvec.begin() ; its != nvec.end() ; its++)
        std::cout << *its << " ";
    
    std::cout << std::endl;
    
    for (itf = fvec.begin() ; itf != fvec.end() ; itf++)
        std::cout << *itf << " ";
}