/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbajrami <tbajrami@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 08:34:32 by tbajrami          #+#    #+#             */
/*   Updated: 2021/04/21 16:25:44 by tbajrami         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
#include "RandomAccessIterator.hpp"
#include "List.hpp"
#include "Map.hpp"
#include <vector>
#include <list>
#include <stack>
#include <queue>

bool is_even(const int &value) {return !(value % 2);}

struct is_odd {bool operator() (const int &value) {return (value % 2);} };

bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

struct is_near {
	bool operator() (double first, double second)
	{ return (fabs(first-second)<5.0); }
};

bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

bool compare_nocase (const std::string& first, const std::string& second)
{
	unsigned int i=0;
	while ( (i<first.length()) && (i<second.length()) )
	{
		if (tolower(first[i])<tolower(second[i])) return true;
		else if (tolower(first[i])>tolower(second[i])) return false;
		++i;
	}
	return ( first.length() < second.length() );
}

int main()
{

	// std::cout << "\n######### --------- VECTOR --------- #########\n\n";

	// ft::Vector<int> b(10, 0);
	// std::vector<int> c(10, 0);

	// std::cout << "\n######################################";
	// std::cout << "\n##### ----- SIZE FUNCTIONS ----- #####";
	// std::cout << "\n######################################\n";

	// std::cout << "\n### --- vector(10, 0) then assign value 1 to 10 --- ###\n";

	// for (size_t i = 0 ; i < b.size() ; i++)
	//     b.at(i) = i + 1;
	// for (size_t j = 0 ; j < c.size() ; j++)
	//     c.at(j) = j + 1;

	// std::cout << "\nft vector size: " << b.size() << std::endl;
	// std::cout << "sd vector size: " << c.size() << std::endl;

	// std::cout << "\nft vector capacity: " << b.capacity() << std::endl;
	// std::cout << "sd vector capacity: " << c.capacity() << std::endl;

	// std::cout << "\nft vector: ";
	// for (size_t i = 0 ; i < b.size() ; i++)
	//     std::cout << ' ' << b.at(i);
	// std::cout << '\n';

	// std::cout << "sd vector: ";
	// for (size_t i = 0 ; i < c.size() ; i++)
	//     std::cout << ' ' << c.at(i);
	// std::cout << '\n';

	// std::cout << "\n### --- resize(5) --- ###\n";

	// b.resize(5);
	// c.resize(5);

	// std::cout << "\nft vector size: " << b.size() << std::endl;
	// std::cout << "sd vector size: " << c.size() << std::endl;

	// std::cout << "\nft vector capacity: " << b.capacity() << std::endl;
	// std::cout << "sd vector capacity: " << c.capacity() << std::endl;

	// std::cout << "\nft vector: ";
	// for (size_t i = 0 ; i < b.size() ; i++)
	//     std::cout << ' ' << b.at(i);
	// std::cout << '\n';

	// std::cout << "sd vector: ";
	// for (size_t i = 0 ; i < c.size() ; i++)
	//     std::cout << ' ' << c.at(i);
	// std::cout << '\n';
	
	// std::cout << "\n### --- resize(8, 100) --- ###\n";

	// b.resize(8,100);
	// c.resize(8,100);

	// std::cout << "\nft vector size: " << b.size() << std::endl;
	// std::cout << "sd vector size: " << c.size() << std::endl;

	// std::cout << "\nft vector capacity: " << b.capacity() << std::endl;
	// std::cout << "sd vector capacity: " << c.capacity() << std::endl;
	
	// std::cout << "\nft vector: ";
	// for (size_t i = 0 ; i < b.size() ; i++)
	//     std::cout << ' ' << b.at(i);
	// std::cout << '\n';

	// std::cout << "sd vector: ";
	// for (size_t i = 0 ; i < c.size() ; i++)
	//     std::cout << ' ' << c.at(i);
	// std::cout << '\n';
	
	// std::cout << "\n### --- resize(12) --- ###\n";

	// b.resize(12);
	// c.resize(12);

	// std::cout << "\nft vector size: " << b.size() << std::endl;
	// std::cout << "sd vector size: " << c.size() << std::endl;

	// std::cout << "\nft vector capacity: " << b.capacity() << std::endl;
	// std::cout << "sd vector capacity: " << c.capacity() << std::endl;

	// std::cout << "\nft vector: ";
	// for (size_t i = 0 ; i < b.size() ; i++)
	//     std::cout << ' ' << b.at(i);
	// std::cout << '\n';

	// std::cout << "sd vector: ";
	// for (size_t i = 0 ; i < c.size() ; i++)
	//     std::cout << ' ' << c.at(i);
	// std::cout << '\n';

	// std::cout << "\n### --- max size --- ###\n";
	
	// std::cout << "\nft vector max_size: " << b.max_size() << std::endl;
	// std::cout << "sd vector max_size: " << c.max_size() << std::endl;

	// std::cout << "\n### --- empty ? --- ###\n";

	// std::cout << "\nprevious vectors :";
	// std::cout << "\nft vector empty ? " << b.empty() << std::endl;
	// std::cout << "sd vector empty ? " << c.empty() << std::endl;

	// ft::Vector<int> d;
	// std::vector<int> e;
	
	// std::cout << "\nnew vectors without parameters :\n";
	// std::cout << "ft vector empty ? " << d.empty() << std::endl;
	// std::cout << "sd vector empty ? " << e.empty() << std::endl;

	// std::cout << "\n### --- reserve(10) --- ###\n";

	// b.reserve(10);
	// c.reserve(10);

	// std::cout << "\nft vector size: " << b.size() << std::endl;
	// std::cout << "sd vector size: " << c.size() << std::endl;
	
	// std::cout << "\nft vector capacity: " << b.capacity() << std::endl;
	// std::cout << "sd vector capacity: " << c.capacity() << std::endl;

	// std::cout << "\n### --- reserve(42) --- ###\n";

	// b.reserve(42);
	// c.reserve(42);

	// std::cout << "\nft vector size: " << b.size() << std::endl;
	// std::cout << "sd vector size: " << c.size() << std::endl;

	// std::cout << "\nft vector capacity: " << b.capacity() << std::endl;
	// std::cout << "sd vector capacity: " << c.capacity() << std::endl;

	// std::cout << "\n### --- resize(100) --- ###\n";

	// b.resize(100);
	// c.resize(100);

	// std::cout << "\nft vector size: " << b.size() << std::endl;
	// std::cout << "sd vector size: " << c.size() << std::endl;

	// std::cout << "\nft vector capacity: " << b.capacity() << std::endl;
	// std::cout << "sd vector capacity: " << c.capacity() << std::endl;

	// std::cout << "\n######################################";
	// std::cout << "\n######## ----- ITERATORS ----- #######";
	// std::cout << "\n######################################\n";

	// std::cout << "\n### --- resize(20) + using iterators --- ###\n";

	// b.resize(20);
	// c.resize(20);

	// for (size_t i = 0 ; i < b.size() ; i++)
	//     b.at(i) = i + 1;
	// for (size_t j = 0 ; j < c.size() ; j++)
	//     c.at(j) = j + 1;

	// std::vector<int>::iterator its;
	// ft::Vector<int>::iterator itf;

	// std::cout << "\nft vector:\n";
	// for (itf = b.begin() ; itf != b.end() ; itf++)
	//     std::cout << *itf << " ";

	// std::cout << "\nsd vector:\n";
	// for (its = c.begin() ; its != c.end() ; its++)
	//     std::cout << *its << " ";
	// std::cout << "\n\n";

	// std::cout << "\n--end:\n";
	// std::cout << *(--itf) << std::endl;
	// std::cout << *(--its) << std::endl;

	// ++itf;
	// ++its;

	// std::cout << "\nsd begin[5]: " << c.begin()[5] << std::endl;
	// std::cout << "ft begin[5]: " << b.begin()[5] << std::endl;

	// std::cout << "\n### --- reverse iterators --- ###\n\n";

	// std::cout << "sd rbegin: " << *(c.rbegin()) << std::endl;
	// std::cout << "ft rbegin: " << *(b.rbegin()) << std::endl << std::endl;

	// std::cout << "sd rend - 1: " << *(c.rend() - 1) << std::endl;
	// std::cout << "ft rend - 1: " << *(b.rend() - 1) << std::endl << std::endl;

	// std::cout << "sd rbegin + 1: " << *(c.rbegin() + 1) << std::endl;
	// std::cout << "ft rbegin + 1: " << *(b.rbegin() + 1) << std::endl << std::endl;

	// std::cout << "sd rbegin[5]: " << c.rbegin()[5] << std::endl;
	// std::cout << "ft rbegin[5]: " << b.rbegin()[5] << std::endl;


	// std::cout << "\n### --- overload operators --- ###\n";

	// std::vector<int>::iterator its2 = c.end();
	// ft::Vector<int>::iterator itf2 = b.end();

	// std::cout << "\nend iterators compared to previous operators" << std::endl;
	// std::cout << "sd vector: " << (its == its2) << std::endl;
	// std::cout << "ft vector: " << (itf == itf2) << std::endl;

	// std::cout << "\ndecrement one of them" << std::endl;

	// its--;
	// itf--;

	// std::cout << "sd vector: " << (its == its2) << std::endl;
	// std::cout << "ft vector: " << (itf == itf2) << std::endl;

	// std::cout << "\nbegin = begin + 5" << std::endl;

	// its = c.begin() + 5;
	// itf = b.begin() + 5;

	// std::cout << "sd vector: " << *its << std::endl;
	// std::cout << "ft vector: " << *itf << std::endl;

	// std::cout << "\n+=5" << std::endl;

	// its += 5;
	// itf += 5;

	// std::cout << "sd vector: " << *its << std::endl;
	// std::cout << "ft vector: " << *itf << std::endl;

	// std::cout << "\n-=10" << std::endl;

	// its -=10;
	// itf -=10;

	// std::cout << "sd vector: " << *its << std::endl;
	// std::cout << "ft vector: " << *itf << std::endl;

	// std::cout << "\n######################################";
	// std::cout << "\n####### --- ELEMENT  ACCESS --- ######";
	// std::cout << "\n######################################\n";

	// std::cout << "\nsd vector at(5): " << c.at(5) << std::endl;
	// std::cout << "ft vector at(5): " << b.at(5) << std::endl;

	// std::cout << "\nsd vector[5]: " << c[5] << std::endl;
	// std::cout << "ft vector[5]: " << b[5] << std::endl;

	// std::cout << "\nsd front: " << c.front() << std::endl;
	// std::cout << "ft front: " << b.front() << std::endl;

	// std::cout << "\nsd back: " << c.back() << std::endl;
	// std::cout << "ft back: " << b.back() << std::endl;

	// std::cout << "\n######################################";
	// std::cout << "\n######## ----- DEEP COPY ----- #######";
	// std::cout << "\n######################################\n";

	// ft::Vector<int> ft_copy(b);
	// ft::Vector<int>::iterator itc;

	// std::cout << "\nft vector:\n";
	// for (itf = b.begin() ; itf != b.end() ; itf++)
	//     std::cout << *itf << " ";

	// std::cout << "\n\nchange copy[5]: = 0\n";
	// ft_copy[5] = 0;
	// std::cout << "\ncp vector:\n";
	// for (itc = ft_copy.begin() ; itc != ft_copy.end() ; itc++)
	//     std::cout << *itc << " ";
	// std::cout << "\n\n";

	// std::cout << "\n######################################";
	// std::cout << "\n######## ----- MODIFIERS ----- #######";
	// std::cout << "\n######################################\n";

	// std::cout << "\n### --- assign (value) --- ###\n\n";

	// std::vector<int> std_copy(c);

	// std::cout << "\n### --- std --- ###\n\n";

	// std::cout << "capacity before assign: " << c.capacity() << std::endl;
	// c.assign(7, 100);
	// std::cout << "assign(7, 100): ";
	// for (its = c.begin() ; its != c.end() ; its++)
	//     std::cout << *its << " ";
	// std::cout << "\ncapacity after assign: " << c.capacity() << std::endl;
	// c.assign(300, 5);
	// std::cout << "assign(300, 5): ";
	// for (its = c.begin() ; its != c.end() ; its++)
	//     std::cout << *its << " ";
	// std::cout << "\ncapacity after assign: " << c.capacity() << std::endl;

	// std::cout << "\n### --- ft --- ###\n\n";

	// std::cout << "capacity before assign: " << b.capacity() << std::endl;
	// b.assign(7, 100);
	// std::cout << "assign(7, 100): ";
	// for (itf = b.begin() ; itf != b.end() ; itf++)
	//     std::cout << *itf << " ";
	// std::cout << "\ncapacity after assign: " << b.capacity() << std::endl;
	// b.assign(300, 5);
	// std::cout << "assign(300, 5): ";
	// for (itf = b.begin() ; itf != b.end() ; itf++)
	//     std::cout << *itf << " ";
	// std::cout << "\ncapacity after assign: " << b.capacity() << std::endl;

	// std::cout << "\n### --- assign (range) --- ###\n\n";
	
	// std::cout << "\n### --- std --- ###\n\n";

	// c.assign(std_copy.begin(), std_copy.end());
	// std::cout << "assign(vec(300) to vec 1-20): ";
	// for (its = c.begin() ; its != c.end() ; its++)
	//     std::cout << *its << " ";
	// std::cout << "\ncapacity after assign: " << c.capacity() << std::endl;

	// std::vector<int> std5(5, 5);

	// std5.assign(c.begin(), c.end());
	// std::cout << "\nassign(vec(5) to vec 1-20): ";
	// for (its = std5.begin() ; its != std5.end() ; its++)
	//     std::cout << *its << " ";
	// std::cout << "\ncapacity after assign: " << std5.capacity() << std::endl;

	// std::cout << "\n### --- ft --- ###\n\n";

	// b.assign(ft_copy.begin(), ft_copy.end());
	// std::cout << "assign(vec(300) to vec 1-20): ";
	// for (itf = b.begin() ; itf != b.end() ; itf++)
	//     std::cout << *itf << " ";
	// std::cout << "\ncapacity after assign: " << b.capacity() << std::endl;

	// ft::Vector<int> ft5(5, 5);

	// ft5.assign(b.begin(), b.end());
	// std::cout << "\nassign(vec(5) to vec 1-20): ";
	// for (itf = ft5.begin() ; itf != ft5.end() ; itf++)
	//     std::cout << *itf << " ";
	// std::cout << "\ncapacity after assign: " << ft5.capacity() << std::endl;

	// std::cout << "\n### --- assign (reverse iterators) --- ###\n\n";

	// std::cout << "\n### --- std --- ###\n\n";

	// c.assign(300, 5);

	// c.assign(std5.rbegin(), std5.rend());
	// std::cout << "assign(vec(300) to vec 1-20): ";
	// for (its = c.begin() ; its != c.end() ; its++)
	//     std::cout << *its << " ";
	// std::cout << "\ncapacity after assign: " << c.capacity() << std::endl;

	// std5.assign(5, 5);

	// std5.assign(c.rbegin(), c.rend());
	// std::cout << "\nassign(vec(5) to vec 1-20): ";
	// for (its = std5.begin() ; its != std5.end() ; its++)
	//     std::cout << *its << " ";
	// std::cout << "\ncapacity after assign: " << std5.capacity() << std::endl;

	// std::cout << "\n### --- ft --- ###\n\n";

	// b.assign(300, 5);

	// b.assign(ft5.rbegin(), ft5.rend());
	// std::cout << "assign(vec(300) to vec 1-20): ";
	// for (itf = b.begin() ; itf != b.end() ; itf++)
	//     std::cout << *itf << " ";
	// std::cout << "\ncapacity after assign: " << b.capacity() << std::endl;

	// ft5.assign(5, 5);

	// ft5.assign(b.rbegin(), b.rend());
	// std::cout << "\nassign(vec(5) to vec 1-20): ";
	// for (itf = ft5.begin() ; itf != ft5.end() ; itf++)
	//     std::cout << *itf << " ";
	// std::cout << "\ncapacity after assign: " << ft5.capacity() << std::endl;

	// std::cout << "\n### --- push_back --- ###\n\n";

	// std::cout << "\n### --- std --- ###\n\n";

	// std::vector<int> nvec;

	// for (size_t i = 0 ; i < 20 ; i++)
	// {
	//     nvec.push_back(i);
	//     std::cout << "capacity: " << nvec.capacity() << std::endl;
	// }
	// for (size_t i = 0 ; i < 20 ; i++)
	//     std::cout << "std[" << i << "]: " << nvec[i] << std::endl;

	// std::cout << "\n### --- ft --- ###\n\n";

	// ft::Vector<int> fvec;

	// for (size_t i = 0 ; i < 20 ; i++)
	// {
	//     fvec.push_back(i);
	//     std::cout << "capacity: " << fvec.capacity() << std::endl;
	// }

	// for (size_t i = 0 ; i < 20 ; i++)
	//     std::cout << "ft[" << i << "]: " << fvec[i] << std::endl;

	// nvec.pop_back();
	// fvec.pop_back();

	// std::cout << "\n### --- 1 pop_back (std then ft) --- ###\n\n";

	// for (its = nvec.begin() ; its != nvec.end() ; its++)
	//     std::cout << *its << " ";
	
	// std::cout << std::endl;
	
	// for (itf = fvec.begin() ; itf != fvec.end() ; itf++)
	//     std::cout << *itf << " ";
	
	// std::cout << "\n\n### --- insert 100 position 5 --- ###\n\n";

	// std::vector<int>::iterator spos = nvec.begin() + 5;
	// ft::Vector<int>::iterator fpos = fvec.begin() + 5;

	// nvec.insert(spos, 100);
	// fvec.insert(fpos, 100);

	// for (its = nvec.begin() ; its != nvec.end() ; its++)
	//     std::cout << *its << " ";
	
	// std::cout << std::endl;
	
	// for (itf = fvec.begin() ; itf != fvec.end() ; itf++)
	//     std::cout << *itf << " ";

	// std::cout << "\n\n### --- insert 8 * 200 position 5 --- ###\n\n";

	// spos = nvec.begin() + 5;
	// fpos = fvec.begin() + 5;

	// nvec.insert(spos, 8, 200);
	// fvec.insert(fpos, 8, 200);

	// for (its = nvec.begin() ; its != nvec.end() ; its++)
	//     std::cout << *its << " ";
	
	// std::cout << std::endl;
	
	// for (itf = fvec.begin() ; itf != fvec.end() ; itf++)
	//     std::cout << *itf << " ";

	// std::vector<int>nvec2;
	// ft::Vector<int>fvec2;

	// for (size_t i = 0 ; i < 20 ; i++)
	//     nvec2.push_back(i + 50);

	// for (size_t i = 0 ; i < 20 ; i++)
	//     fvec2.push_back(i + 50);

	// std::cout << "\n\n### --- insert range 53-57 position 3 --- ###\n\n";

	// nvec.insert(spos, nvec2.begin() + 3, nvec2.begin() + 8);
	// fvec.insert(fpos, fvec2.begin() + 3, fvec2.begin() + 8);

	// for (its = nvec.begin() ; its != nvec.end() ; its++)
	//     std::cout << *its << " ";
	
	// std::cout << std::endl;
	
	// for (itf = fvec.begin() ; itf != fvec.end() ; itf++)
	//     std::cout << *itf << " ";

	// int ar[5] = {10, 20, 30, 40, 50};

	// std::cout << "\n\n### --- insert int range [10, 20, 30] position 3 --- ###\n\n";

	// fpos = fvec.begin() + 5;
	// spos = nvec.begin() + 5;

	// nvec.insert(spos, ar, ar + 3);
	// fvec.insert(fpos, ar, ar + 3);    

	// for (its = nvec.begin() ; its != nvec.end() ; its++)
	//     std::cout << *its << " ";
	
	// std::cout << std::endl;
	
	// for (itf = fvec.begin() ; itf != fvec.end() ; itf++)
	//     std::cout << *itf << " ";
	
	// std::cout << "\n\n### --- erase position 20 --- ###\n\n";

	// nvec.erase(nvec.begin() + 20);
	// fvec.erase(fvec.begin() + 20);

	// for (its = nvec.begin() ; its != nvec.end() ; its++)
	//     std::cout << *its << " ";
	
	// std::cout << std::endl;
	
	// for (itf = fvec.begin() ; itf != fvec.end() ; itf++)
	//     std::cout << *itf << " ";
	
	// std::cout << "\n\n### --- erase position 10-20 --- ###\n\n";

	// nvec.erase(nvec.begin() + 10, nvec.begin() + 20);
	// fvec.erase(fvec.begin() + 10, fvec.begin() + 20);

	// for (its = nvec.begin() ; its != nvec.end() ; its++)
	//     std::cout << *its << " ";
	
	// std::cout << std::endl;
	
	// for (itf = fvec.begin() ; itf != fvec.end() ; itf++)
	//     std::cout << *itf << " ";

	// std::cout << "\n\n### --- swap --- ###\n\n";

	// ft::Vector<int> vec0(5, 5);
	// ft::Vector<int> vec1(10, 10);
	// std::vector<int> vec2(10, 10);

	// ft::Vector<int>::iterator fb = vec0.begin();

	// std::cout << "iterator set to vec(0)[0]: " << *fb << "\n\n";

	// std::cout << "vec0: ";
	// for (itf = vec0.begin() ; itf != vec0.end() ; itf++)
	//     std::cout << *itf << " ";
	// std::cout << "\nvec1: ";
	// for (itf = vec1.begin() ; itf != vec1.end() ; itf++)
	//     std::cout << *itf << " ";

	// vec0.swap(vec1);

	// std::cout << "\n\nafter swap vec0: ";
	// for (itf = vec0.begin() ; itf != vec0.end() ; itf++)
	//     std::cout << *itf << " ";
	// std::cout << "\nafter swap vec1: ";
	// for (itf = vec1.begin() ; itf != vec1.end() ; itf++)
	//     std::cout << *itf << " ";

	// std::cout << "\n\niterator set: " << *fb << std::endl;

	// std::cout << "\n\n### --- clear --- ###\n\n";

	// vec0.clear();
	// vec2.clear();

	// std::cout << "ft cleared size/capacity: " << vec0.size() << "/" << vec0.capacity() << std::endl;
	// std::cout << "sd cleared size/capacity: " << vec2.size() << "/" << vec2.capacity() << std::endl;

	// std::cout << "\n\n### --- non member overload swap --- ###\n\n";

	// std::cout << "before swap vec0: ";
	// for (itf = vec0.begin() ; itf != vec0.end() ; itf++)
	//     std::cout << *itf << " ";
	// std::cout << "\nbefore swap vec1: ";
	// for (itf = vec1.begin() ; itf != vec1.end() ; itf++)
	//     std::cout << *itf << " ";

	// swap(vec0, vec1);

	// std::cout << "\n\nafter swap vec0: ";
	// for (itf = vec0.begin() ; itf != vec0.end() ; itf++)
	//     std::cout << *itf << " ";
	// std::cout << "\nafter swap vec1: ";
	// for (itf = vec1.begin() ; itf != vec1.end() ; itf++)
	//     std::cout << *itf << " ";
	

	// std::cout << "\n\n### --- relational operators --- ###\n\n";

	// std::vector<int> svec0(5, 100);
	// std::vector<int> svec1(6, 100);
	// std::vector<int> svec2(4, 110);
	// std::vector<std::string> svec3(2, "bla");
	// std::vector<std::string> svec4(3, "bla");
	// std::vector<std::string> svec5(3, "abc");

	// ft::Vector<int> mvec0(5, 100);
	// ft::Vector<int> mvec1(6, 100);
	// ft::Vector<int> mvec2(4, 110);
	// ft::Vector<std::string> mvec3(2, "bla");
	// ft::Vector<std::string> mvec4(3, "bla");
	// ft::Vector<std::string> mvec5(3, "abc");

	// std::cout << "\n### --- std --- ###\n\n";

	// std::cout << "(5, 100) < (4, 110): " << (svec0 < svec1) << "\n";
	// std::cout << "(6, 100) < (4, 110): " << (svec1 < svec2) << "\n";
	// std::cout << "(2, bla) < (3, bla): " << (svec3 < svec4) << "\n";
	// std::cout << "(2, bla) < (3, abc): " << (svec3 < svec5) << "\n";
	// std::cout << "(2, bla) == (3, bla): " << (svec3 == svec4) << "\n";

	// std::cout << "\n### --- ft --- ###\n\n";

	// std::cout << "(5, 100) < (4, 110): " << (mvec0 < mvec1) << "\n";
	// std::cout << "(6, 100) < (4, 110): " << (mvec1 < mvec2) << "\n";
	// std::cout << "(2, bla) < (3, bla): " << (mvec3 < mvec4) << "\n";
	// std::cout << "(2, bla) < (3, abc): " << (mvec3 < mvec5) << "\n";
	// std::cout << "(2, bla) == (3, bla): " << (mvec3 == mvec4) << "\n";

	// int a[5] = {1, 2, 3, 4, 5};

	// ft::Vector<int> aa(5, 10);
	// std::vector<int> bb(a, a + 3);
	// ft::Vector<int> cc(a, a + 3);

	// std::cout << "\n### --- construct vector with range --- ###\n\n";

	// std::cout << "std: ";
	// for (std::vector<int>::iterator itf = bb.begin() ; itf != bb.end() ; itf++)
	//     std::cout << *itf << " ";

	// std::cout << "\nft: ";

	// for (ft::Vector<int>::iterator itf = cc.begin() ; itf != cc.end() ; itf++)
	//     std::cout << *itf << " ";

	// std::cout << "\n\n######### --------- STACK --------- #########\n\n";

	// std::stack<int> stst0;
	// ft::Stack<int> ftst0;

	// std::stack<int> stst1;
	// ft::Stack<int> ftst1;

	// std::cout << "\n### --- push 50, 295, 0 then pop one by one --- ###\n\n";

	// stst0.push(50);
	// stst0.push(295);
	// stst0.push(0);

	// ftst0.push(50);
	// ftst0.push(295);
	// ftst0.push(0);

	// std::cout << "\n### --- std --- ###\n\n";

	// while (!stst0.empty())
	// {
	//     std::cout << stst0.top() << " is on top\n";
	//     stst0.pop();
	// }
	// std::cout << "\n### --- ft --- ###\n\n";
	// while (!ftst0.empty())
	// {
	//     std::cout << ftst0.top() << " is on top\n";
	//     ftst0.pop();
	// }

	// stst0.push(50);
	// stst0.push(295);
	// stst0.push(0);

	// stst1.push(50);
	// stst1.push(295);
	// stst1.push(2);

	// ftst0.push(50);
	// ftst0.push(295);
	// ftst0.push(0);

	// ftst1.push(50);
	// ftst1.push(295);
	// ftst1.push(2);

	// std::cout << "\n### --- std --- ###\n\n";

	// std::cout << "(50, 295, 0) < (50, 295, 2): " << (stst0 < stst1) << "\n";
	// stst0.pop();
	// stst0.push(0);
	// stst0.push(0);
	// std::cout << "(50, 295, 0, 0) < (50, 295, 0): " << (stst0 < stst1) << "\n";
	// std::cout << "(50, 295, 0, 0) == (50, 295, 0): " << (stst0 == stst1) << "\n";

	// std::cout << "\n### --- ft --- ###\n\n";

	// std::cout << "(50, 295, 0) < (50, 295, 2): " << (ftst0 < ftst1) << "\n";
	// ftst0.pop();
	// ftst0.push(0);
	// ftst0.push(0);
	// std::cout << "(50, 295, 0, 0) < (50, 295, 0): " << (ftst0 < ftst1) << "\n";
	// std::cout << "(50, 295, 0, 0) == (50, 295, 0): " << (ftst0 == ftst1) << "\n";

	// std::cout << "\n######### --------- QUEUE --------- #########\n\n";

	// std::queue<int> stqu0;
	// ft::Queue<int> ftqu0;

	// std::queue<int> stqu1;
	// ft::Queue<int> ftqu1;

	// stqu0.push(50);
	// stqu0.push(295);
	// stqu0.push(1);

	// ftqu0.push(50);
	// ftqu0.push(295);
	// ftqu0.push(1);

	// std::cout << "\n### --- push 50, 295, 1 then pop one by one --- ###\n\n";

	// std::cout << "std: " << stqu0.back() << " is on back\n";
	// std::cout << "ft: " << ftqu0.back() << " is on back\n";

	// std::cout << "\n### --- std --- ###\n\n";

	// while (!stqu0.empty())
	// {
	//     std::cout << stqu0.front() << " is on front\n";
	//     stqu0.pop();
	// }

	// std::cout << "\n### --- ft --- ###\n\n";
	// while (!ftqu0.empty())
	// {
	//     std::cout << ftqu0.front() << " is on front\n";
	//     ftqu0.pop();
	// }

	// stqu0.push(50);
	// stqu0.push(295);
	// stqu0.push(0);

	// ftqu0.push(50);
	// ftqu0.push(295);
	// ftqu0.push(0);

	// stqu1.push(50);
	// stqu1.push(295);
	// stqu1.push(2);

	// ftqu1.push(50);
	// ftqu1.push(295);
	// ftqu1.push(2);

	// std::cout << "\n### --- std --- ###\n\n";

	// std::cout << "(50, 295, 0) < (50, 295, 2): " << (stqu0 < stqu1) << "\n";
	// stqu0.pop();
	// stqu0.push(0);
	// stqu0.push(0);
	// std::cout << "(50, 295, 0, 0) < (50, 295, 0): " << (stqu0 < stqu1) << "\n";
	// std::cout << "(50, 295, 0, 0) == (50, 295, 0): " << (stqu0 == stqu1) << "\n";

	// std::cout << "\n### --- ft --- ###\n\n";

	// std::cout << "(50, 295, 0) < (50, 295, 2): " << (ftqu0 < ftqu1) << "\n";
	// ftqu0.pop();
	// ftqu0.push(0);
	// ftqu0.push(0);
	// std::cout << "(50, 295, 0, 0) < (50, 295, 0): " << (ftqu0 < ftqu1) << "\n";
	// std::cout << "(50, 295, 0, 0) == (50, 295, 0): " << (ftqu0 == ftqu1) << "\n";

	

	// std::cout << "\n######### --------- LIST --------- #########\n\n";

	// std::list<int> slst0(5, 5);
	// ft::List<int> flst0(5, 5);
	// std::list<int> slst1;
	// ft::List<int> flst1;

	// std::cout << "\n######### --------- Capacity --------- #########\n\n";

	// std::cout << "sd list(5, 5) empty ?: " << slst0.empty() << std::endl;
	// std::cout << "ft list(5, 5) empty ?: " << flst0.empty() << std::endl;
	// std::cout << "sd list() empty ?: " << slst1.empty() << std::endl;
	// std::cout << "ft list() empty ?: " << flst1.empty() << std::endl;

	// std::cout << "\nsd list(5, 5) size: " << slst0.size() << std::endl;
	// std::cout << "ft list(5, 5) size: " << flst0.size() << std::endl;
	// std::cout << "sd list() size: " << slst1.size() << std::endl;
	// std::cout << "ft list() size: " << flst1.size() << std::endl;

	// std::cout << "\nsd list(5, 5) max size: " << slst0.max_size() << std::endl;
	// std::cout << "ft list(5, 5) max size: " << flst0.max_size() << std::endl;

	// std::cout << "ft list front: " << flst0.front() << std::endl;
	// std::cout << "ft list back: " << flst0.back() << std::endl;

	// std::cout << "\n######### --------- push front 1, push back 2 --------- #########\n\n";

	// flst0.push_front(1);
	// flst0.push_back(2);

	// slst0.push_front(1);
	// slst0.push_back(2);

	// std::cout << "ft list front: " << flst0.front() << std::endl;
	// std::cout << "ft list back: " << flst0.back() << std::endl;

	// std::cout << "sd list front: " << slst0.front() << std::endl;
	// std::cout << "sd list back: " << slst0.back() << std::endl;

	// std::cout << "\n\n######### --------- iterators --------- #########\n\n";

	// ft::List<int>::iterator lit;
	// std::list<int>::iterator lite;

	// for (lite = slst0.begin() ; lite != slst0.end() ; lite++)
	// {
	//     std::cout << *lite << " ";
	// }

	// std::cout << "\n";

	// for (lit = flst0.begin() ; lit != flst0.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }

	// std::cout << "\n\n######### --------- reverse iterators --------- #########\n\n";

	// ft::List<int>::reverse_iterator rlit;
	// std::list<int>::reverse_iterator rlite;

	// for (rlite = slst0.rbegin() ; rlite != slst0.rend() ; rlite++)
	// {
	//     std::cout << *rlite << " ";
	// }

	// std::cout << "\n";

	// for (rlit = flst0.rbegin() ; rlit != flst0.rend() ; rlit++)
	// {
	//     std::cout << *rlit << " ";
	// }

	// std::cout << "\n\n######### --------- iterators on empty list --------- #########\n\n";

	// std::list<int> eslst;
	// ft::List<int> eflst;

	// std::cout << "sd begin: " << *eslst.begin() << "\n";
	// std::cout << "ft begin: " << *eflst.begin() << "\n";
	// std::cout << "\nsd rbegin: " << *eslst.rbegin() << "\n";
	// std::cout << "ft rbegin: " << *eflst.rbegin() << "\n";

	// std::cout << "\n\n######### --------- iterate on empty list (nothing happens) --------- #########\n\n";

	// for (lite = eslst.begin() ; lite != eslst.end() ; lite++)
	// {
	//     std::cout << *lite << " ";
	// }

	// for (lit = eflst.begin() ; lit != eflst.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }

	// std::cout << "\n\n######### --------- iterators on empty lists + push_back(1) --------- #########\n\n";

	// eslst.push_back(1);
	// eflst.push_back(1);

	// for (lite = eslst.begin() ; lite != eslst.end() ; lite++)
	// {
	//     std::cout << *lite << " ";
	// }

	// std::cout << "\n";

	// for (lit = eflst.begin() ; lit != eflst.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }

	// eslst.pop_back();
	// eflst.pop_back();

	// std::cout << "\n\n######### --------- reverse iterators on empty list (nothing happens) --------- #########\n";

	// std::list<int> eslst2;
	// ft::List<int> eflst2;

	// for (rlite = eslst2.rbegin() ; rlite != eslst2.rend() ; rlite++)
	// {
	//     std::cout << *rlite << " ";
	// }

	// std::cout << "\n";

	// for (rlit = eflst2.rbegin() ; rlit != eflst2.rend() ; rlit++)
	// {
	//     std::cout << *rlit << " ";
	// }

	// std::cout << "\n\n######### --------- reverse iterators on empty lists + push_back(1) --------- #########\n\n";

	// eslst2.push_back(1);
	// eflst2.push_back(1);

	// for (rlite = eslst2.rbegin() ; rlite != eslst2.rend() ; rlite++)
	// {
	//     std::cout << *rlite << " ";
	// }

	// std::cout << "\n";

	// for (rlit = eflst2.rbegin() ; rlit != eflst2.rend() ; rlit++)
	// {
	//     std::cout << *rlit << " ";
	// }

	// std::cout << "\n\n######### --------- construct with iterator --------- #########\n\nsd: ";

	// std::list<int> islst(slst0.begin(), slst0.end());
	// ft::List<int> iflst(flst0.begin(), flst0.end());

	// for (lite = islst.begin() ; lite != islst.end() ; lite++)
	// {
	//     std::cout << *lite << " ";
	// }

	// std::cout << "\nft: ";

	// for (lit = iflst.begin() ; lit != iflst.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }

	// std::cout << "\n\n######### --------- construct with reverse iterator --------- #########\n\nsd: ";

	// islst = std::list<int>(slst0.rbegin(), slst0.rend());
	// iflst = ft::List<int>(flst0.rbegin(), flst0.rend());

	// for (lite = islst.begin() ; lite != islst.end() ; lite++)
	// {
	//     std::cout << *lite << " ";
	// }

	// std::cout << "\nft: ";

	// for (lit = iflst.begin() ; lit != iflst.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }

	// std::cout << "\n\n######### --------- assign list(3, 5) --------- #########\n\nsd: ";

	// islst.assign(3, 5);
	// iflst.assign(3, 5);

	// for (lite = islst.begin() ; lite != islst.end() ; lite++)
	// {
	//     std::cout << *lite << " ";
	// }

	// std::cout << "\nft: ";

	// for (lit = iflst.begin() ; lit != iflst.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }

	// std::cout << "\n\n######### --------- assign with iterators (from previous lists) --------- #########\n\nsd: ";

	// islst.assign(slst0.begin(), slst0.end());
	// iflst.assign(flst0.begin(), flst0.end());

	// for (lite = islst.begin() ; lite != islst.end() ; lite++)
	// {
	//     std::cout << *lite << " ";
	// }

	// std::cout << "\nft: ";

	// for (lit = iflst.begin() ; lit != iflst.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }

	// std::cout << "\n\n######### --------- assign with reverse iterators (from previous lists) --------- #########\n\nsd: ";

	// islst.assign(slst0.rbegin(), slst0.rend());
	// iflst.assign(flst0.rbegin(), flst0.rend());

	// for (lite = islst.begin() ; lite != islst.end() ; lite++)
	// {
	//     std::cout << *lite << " ";
	// }

	// std::cout << "\nft: ";

	// for (lit = iflst.begin() ; lit != iflst.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }

	// std::cout << "\n\n######### --------- insert 100 pos 2 --------- #########\n\nsd: ";

	// lite = islst.begin();
	// lite++;
	// lite++;
	// lit = iflst.begin();
	// lit++;
	// lit++;

	// islst.insert(lite, 100);
	// iflst.insert(lit, 100);

	// for (lite = islst.begin() ; lite != islst.end() ; lite++)
	// {
	//     std::cout << *lite << " ";
	// }

	// std::cout << "\nft: ";

	// for (lit = iflst.begin() ; lit != iflst.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }

	// std::cout << "\n\n######### --------- reverse iterating --------- #########\n\nsd: ";
	

	// for (rlite = islst.rbegin() ; rlite != islst.rend() ; rlite++)
	// {
	//     std::cout << *rlite << " ";
	// }

	// std::cout << "\nft: ";

	// for (rlit = iflst.rbegin() ; rlit != iflst.rend() ; rlit++)
	// {
	//     std::cout << *rlit << " ";
	// }

	// std::cout << "\n\n######### --------- insert 30 pos 2 * 5 --------- #########\n\nsd: ";

	// lite = islst.begin();
	// lite++;
	// lite++;
	// lit = iflst.begin();
	// lit++;
	// lit++;

	// islst.insert(lite, 5, 30);
	// iflst.insert(lit, 5, 30);

	// for (lite = islst.begin() ; lite != islst.end() ; lite++)
	// {
	//     std::cout << *lite << " ";
	// }

	// std::cout << "\nft: ";

	// for (lit = iflst.begin() ; lit != iflst.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }

	// std::cout << "\n\n######### --------- reverse iterating --------- #########\n\nsd: ";
	

	// for (rlite = islst.rbegin() ; rlite != islst.rend() ; rlite++)
	// {
	//     std::cout << *rlite << " ";
	// }

	// std::cout << "\nft: ";

	// for (rlit = iflst.rbegin() ; rlit != iflst.rend() ; rlit++)
	// {
	//     std::cout << *rlit << " ";
	// }

	// std::cout << "\n\n######### --------- erase position 2 --------- #########\n\nsd: ";

	// lite = islst.begin();
	// lite++;
	// lit = iflst.begin();
	// lit++;

	// islst.erase(lite);
	// iflst.erase(lit);

	// for (lite = islst.begin() ; lite != islst.end() ; lite++)
	// {
	//     std::cout << *lite << " ";
	// }

	// std::cout << "\nft: ";

	// for (lit = iflst.begin() ; lit != iflst.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }

	// std::cout << "\nsize: " << iflst.size() << "\n";

	// std::cout << "\n\n######### --------- reverse iterating --------- #########\n\nsd: ";    

	// for (rlite = islst.rbegin() ; rlite != islst.rend() ; rlite++)
	// {
	//     std::cout << *rlite << " ";
	// }

	// std::cout << "\nft: ";

	// for (rlit = iflst.rbegin() ; rlit != iflst.rend() ; rlit++)
	// {
	//     std::cout << *rlit << " ";
	// }

	// std::cout << "\n\n######### --------- erase position 2 - 6 --------- #########\n\nsd: ";

	// lite = islst.begin();
	// lite++;
	// lit = iflst.begin();
	// lit++;

	// std::list<int>::iterator lite2 = islst.begin();
	// lite2++;lite2++;lite2++;lite2++;lite2++;
	// ft::List<int>::iterator lit2 = iflst.begin();
	// lit2++;lit2++;lit2++;lit2++;lit2++;

	// islst.erase(lite, lite2);
	// iflst.erase(lit, lit2);

	// for (lite = islst.begin() ; lite != islst.end() ; lite++)
	// {
	//     std::cout << *lite << " ";
	// }

	// std::cout << "\nft: ";

	// for (lit = iflst.begin() ; lit != iflst.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }

	// std::cout << "\nsize: " << iflst.size() << "\n";

	// std::cout << "\n\n######### --------- reverse iterating --------- #########\n\nsd: ";

	// for (rlite = islst.rbegin() ; rlite != islst.rend() ; rlite++)
	// {
	//     std::cout << *rlite << " ";
	// }

	// std::cout << "\nft: ";

	// for (rlit = iflst.rbegin() ; rlit != iflst.rend() ; rlit++)
	// {
	//     std::cout << *rlit << " ";
	// }

	// std::cout << "\n\n### --- swap --- ###\n\n";

	// ft::List<int> lst0(5, 5);
	// ft::List<int> lst1(10, 10);

	// ft::List<int>::iterator fb0 = lst0.begin();

	// std::cout << "iterator set to lst(0)[0]: " << *fb0 << "\n\n";

	// std::cout << "lst0: ";
	// for (lit = lst0.begin() ; lit != lst0.end() ; lit++)
	//     std::cout << *lit << " ";
	// std::cout << "\nlst1: ";
	// for (lit = lst1.begin() ; lit != lst1.end() ; lit++)
	//     std::cout << *lit << " ";

	// lst0.swap(lst1);

	// std::cout << "\n\nafter swap lst0: ";
	// for (lit = lst0.begin() ; lit != lst0.end() ; lit++)
	//     std::cout << *lit << " ";
	// std::cout << "\nafter swap lst1: ";
	// for (lit = lst1.begin() ; lit != lst1.end() ; lit++)
	//     std::cout << *lit << " ";

	// std::cout << "\n\niterator set: " << *fb0 << std::endl;

	// std::cout << "\n\n######### --------- resize (5) --------- #########\n\nsd: ";

	// islst.resize(5);
	// iflst.resize(5);
	
	// for (lite = islst.begin() ; lite != islst.end() ; lite++)
	// {
	//     std::cout << *lite << " ";
	// }

	// std::cout << "\nft: ";

	// for (lit = iflst.begin() ; lit != iflst.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }

	// std::cout << "\n\n######### --------- resize (12, 99) --------- #########\n\nsd: ";

	// islst.resize(12, 99);
	// iflst.resize(12, 99);
	
	// for (lite = islst.begin() ; lite != islst.end() ; lite++)
	// {
	//     std::cout << *lite << " ";
	// }

	// std::cout << "\nft: ";

	// for (lit = iflst.begin() ; lit != iflst.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }

	// std::cout << "\n\n######### --------- lstclear --------- #########\n\nsize: ";

	// lst0.clear();
	// std::cout << lst0.size();
	// std::cout << "\niteration on cleared : (nothing happens)";
	// for (lit = lst0.begin() ; lit != lst0.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }

	// std::cout << "\n\n######### --------- splice 10 20 30 pos 2 --------- #########\n\n";

	// ft::List<int>::iterator ifli = iflst.begin();
	// //ifli++;
	// ifli = iflst.end();

	// ft::List<int> lst2;
	// lst2.push_back(10);lst2.push_back(20);lst2.push_back(30);
	// iflst.splice(ifli, lst2);
	// std::cout << "lst: ";
	// for (lit = iflst.begin() ; lit != iflst.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }
	// std::cout << "\nlst in parameter: ";
	// for (lit = lst2.begin() ; lit != lst2.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }

	// std::cout << "\n\n######### --------- splice lst[2] pos 2 --------- #########\n\n";

	// lst2.push_back(77);lst2.push_back(88);lst2.push_back(99);
	// ft::List<int>::iterator litt = lst2.begin();
	// litt++;
	// ft::List<int>::iterator ifli2 = iflst.begin();
	// //ifli2++;
	// ifli2 = iflst.end();
	// iflst.splice(ifli2, lst2, litt);

	// std::cout << "lst: ";
	// for (lit = iflst.begin() ; lit != iflst.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }
	// std::cout << "\nlst in parameter: ";
	// for (lit = lst2.begin() ; lit != lst2.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }
	// std::cout << "\n\n######### --------- splice lst[2]-lst[4] pos 2 --------- #########\n\n";

	// lst2.push_back(444);
	// lst2.push_back(555);
	// lst2.push_back(666);
	// litt = lst2.begin();
	// ft::List<int>::iterator litt2 = lst2.begin();
	// litt++;
	// litt2++;litt2++;
	// std::cout << "\nlst: ";
	// for (lit = iflst.begin() ; lit != iflst.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }
	// std::cout << "\nlst2: ";
	// for (lit = lst2.begin() ; lit != lst2.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }
	// ft::List<int>::iterator ifli3 = iflst.begin();
	// iflst.splice(++ifli3, lst2, lst2.begin(), litt2);

	// std::cout << "\nlst: ";
	// for (lit = iflst.begin() ; lit != iflst.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }
	// std::cout << "\nlst in parameter: ";
	// for (lit = lst2.begin() ; lit != lst2.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }

	// std::cout << "\nsize " << iflst.size() << " " << lst2.size();

	// std::cout << "\n\n######### --------- splice in empty list --------- #########\n\n";

	// ft::List<int> ef;
	
	// ef.splice(ef.begin(), lst2);
	// std::cout << "\nsplice previous lst in empty lst: ";
	// for (lit = ef.begin() ; lit != ef.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }

	// lst2.push_back(2);lst2.push_back(4);lst2.push_back(6);lst2.push_back(8);
	// ef.clear();
	// litt2 = lst2.begin();
	// litt2++;litt2++;
	// ef.splice(ef.begin(), lst2, litt2);
	// std::cout << "\nsplice 6 in empty lst: ";
	// for (lit = ef.begin() ; lit != ef.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }
	// lst2.push_back(10);
	// litt2 = lst2.begin();
	// litt2++;litt2++;
	// ef.clear();
	// ef.splice(ef.begin(), lst2, lst2.begin(), litt2);

	// std::cout << "\n\n######### --------- remove all 99 --------- #########\n\n";

	// ft::List<int> iflst0(iflst);

	// std::cout << "lst before: ";
	// for (lit = iflst.begin() ; lit != iflst.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }

	// iflst.remove(99);

	// std::cout << "\nlst after: ";
	// for (lit = iflst.begin() ; lit != iflst.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }

	// std::cout << "\n\n######### --------- remove if even (func) --------- #########\n\n";

	// ft::List<int> iflst2(iflst);

	// std::cout << "lst before: ";
	// for (lit = iflst2.begin() ; lit != iflst2.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }

	// iflst2.remove_if(is_even);

	// std::cout << "\nlst after: ";
	// for (lit = iflst2.begin() ; lit != iflst2.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }

	// std::cout << "\n\n######### --------- remove if odd (struct) --------- #########\n\n";

	// std::cout << "lst before: ";
	// for (lit = iflst2.begin() ; lit != iflst2.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }

	// iflst2.remove_if(is_odd());

	// std::cout << "\nlst after: ";
	// for (lit = iflst2.begin() ; lit != iflst2.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }

	// std::cout << "\n\n######### --------- unique - remove all 99 but one --------- #########\n\nbefore: ";

	// for (lit = iflst0.begin() ; lit != iflst0.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }

	// iflst0.unique();

	// std::cout << "\nafter: ";

	// for (lit = iflst0.begin() ; lit != iflst0.end() ; lit++)
	// {
	//     std::cout << *lit << " ";
	// }

	// std::cout << "\n\n######### --------- unique - remove with same integral part then near (diff < 5) --------- #########\n\nbefore: ";

	// double mydoubles[]={2.72,  3.14,  12.15, 12.77, 12.77, 15.3, 72.25, 72.25, 73.0, 73.35 };
	// ft::List<double> mylist(mydoubles, mydoubles+10);

	// mylist.unique();

	// ft::List<double>::iterator mlit;

	// for (mlit = mylist.begin() ; mlit != mylist.end() ; mlit++)
	// {
	//     std::cout << *mlit << " ";
	// }
	
	// mylist.unique(same_integral_part);

	// std::cout << "\nafter1: ";

	// for (mlit = mylist.begin() ; mlit != mylist.end() ; mlit++)
	// {
	//     std::cout << *mlit << " ";
	// }

	// mylist.unique(is_near());

	// std::cout << "\nafter2: ";

	// for (mlit = mylist.begin() ; mlit != mylist.end() ; mlit++)
	// {
	//     std::cout << *mlit << " ";
	// }

	// std::cout << "\n\n######### --------- merge {1, 3, 12, 16, 50, 85, 122 } --------- #########\n\nlst: ";

	// ft::List<double> mylist0(mydoubles, mydoubles+10);
	// double mydoubles2[]={1, 3, 12, 16, 50, 85, 122};
	// ft::List<double> mylist2(mydoubles2, mydoubles2+7);

	// mylist0.merge(mylist2);

	// for (mlit = mylist0.begin() ; mlit != mylist0.end() ; mlit++)
	// {
	//     std::cout << *mlit << " ";
	// }

	// std::cout << "\n\n######### --------- merge with integral comparison (cplusplus.com example) --------- #########\n\nlst: ";
	
	// ft::List<double> first;
	// ft::List<double> second;

	// first.push_back (2.2);
	// first.push_back (2.9);
	// first.push_back (3.1);

	// second.push_back (1.4);
	// second.push_back (3.7);
	// second.push_back (7.1);

	// first.merge(second);

	// // (second is now empty)

	// second.push_back (2.1);

	// first.merge(second,mycomparison);

	// for (ft::List<double>::iterator it=first.begin(); it!=first.end(); ++it)
	//     std::cout << *it << " ";
	// std::cout << '\n';

	// std::cout << "\n\n######### --------- sort --------- #########\n\nlst: ";
	
	// double mydoubles3[]={100, 30, -12, 16616, 50, 825, 122};
	// ft::List<double> mylist3(mydoubles3, mydoubles3+7);

	// mylist3.sort();

	// for (mlit = mylist3.begin() ; mlit != mylist3.end() ; mlit++)
	// {
	//     std::cout << *mlit << " ";
	// }

	// std::cout << "\n\n######### --------- sort w/ class compare (cplusplus.com example) --------- #########\n\nlst: ";

	// ft::List<std::string> mlst4;
	// ft::List<std::string>::iterator strit;
	// mlst4.push_back ("one");
	// mlst4.push_back ("two");
	// mlst4.push_back ("Three");

	// std::cout << "mlst4 contains:";
	// for (strit=mlst4.begin(); strit!=mlst4.end(); ++strit)
	// std::cout << ' ' << *strit;
	// std::cout << '\n';

	// mlst4.sort();

	// std::cout << "mlst4 contains (simple sort):";
	// for (strit=mlst4.begin(); strit!=mlst4.end(); ++strit)
	// std::cout << ' ' << *strit;
	// std::cout << '\n';

	// mlst4.sort(compare_nocase);

	// std::cout << "mlst4 contains (comparison not case sensitive):";
	// for (strit=mlst4.begin(); strit!=mlst4.end(); ++strit)
	// std::cout << ' ' << *strit;
	// std::cout << '\n';

	// std::cout << "\n\n######### --------- reverse --------- #########\n\nlst: ";

	// mylist3.reverse();

	// for (mlit = mylist3.begin() ; mlit != mylist3.end() ; mlit++)
	// {
	//     std::cout << *mlit << " ";
	// }

	// std::cout << "\n\n######### --------- operators (cplusplus.com test)--------- #########\n\n";

	// ft::List<int> a; a.push_back(10);a.push_back(20);a.push_back(30);
	// ft::List<int> b; b.push_back(10);b.push_back(20);b.push_back(30);
	// ft::List<int> c; c.push_back(30);c.push_back(20);c.push_back(10);

	// if (a==b) std::cout << "a and b are equal\n";
	// if (b!=c) std::cout << "b and c are not equal\n";
	// if (b<c) std::cout << "b is less than c\n";
	// if (c>b) std::cout << "c is greater than b\n";
	// if (a<=b) std::cout << "a is less than or equal to b\n";
	// if (a>=b) std::cout << "a is greater than or equal to b\n";

	std::cout << "\n######### --------- MAP --------- #########\n\n";

	ft::Map<char, int> fmap;
	std::map<char, int> smap;

	std::pair<char, int> p0('a', 10);
	std::pair<char, int> p1('b', 0);
	std::pair<char, int> p2('f', 4);
	std::pair<char, int> p3('c', 1200);

	fmap.insert(p0);
	fmap.insert(p1);
	fmap.insert(p2);
	fmap.insert(p3);

	smap.insert(p0);
	smap.insert(p1);
	smap.insert(p2);
	smap.insert(p3);

	ft::Map<char, int>::iterator itf;
	std::map<char, int>::iterator its;

	std::cout << "ft:\n";

	for (itf = fmap.begin() ; itf != fmap.end() ; itf++)
		std::cout << (*itf).first << ": " << (*itf).second << std::endl;

	std::cout << "\nstd:\n";

	for (its = smap.begin() ; its != smap.end() ; its++)
		std::cout << (*its).first << ": " << (*its).second << std::endl;
	
	ft::Map<char, int> ffmap(fmap.begin(), fmap.end());

	std::cout << "\n\n######### --------- iterator constructor --------- #########\n\n";

	for (itf = ffmap.begin() ; itf != ffmap.end() ; itf++)
		std::cout << (*itf).first << ": " << (*itf).second << std::endl;
	
	ft::Map<char, int> fffmap(fmap);

	std::cout << "\n\n######### --------- copy constructor --------- #########\n\n";

	for (itf = fffmap.begin() ; itf != fffmap.end() ; itf++)
		std::cout << (*itf).first << ": " << (*itf).second << std::endl;

	std::cout << "\n\n######### --------- reverse iterator --------- #########\n\nft:\n";

	ft::Map<char, int>::reverse_iterator ritf;
	std::map<char, int>::reverse_iterator rits;

	for (ritf = fmap.rbegin() ; ritf != fmap.rend() ; ritf++)
		std::cout << (*ritf).first << ": " << (*ritf).second << std::endl;

	std::cout << "\nstd:\n";

	for (rits = smap.rbegin() ; rits != smap.rend() ; rits++)
		std::cout << (*rits).first << ": " << (*rits).second << std::endl;
}
