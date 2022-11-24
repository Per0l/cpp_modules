/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:23:27 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/24 18:03:40 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
#include <vector>
#include <set>
#include <deque>
#include <iostream>
#include <iomanip>
#include <sys/time.h>

void random_seed() {
	struct timeval time_now;
	gettimeofday(&time_now, 0);
	time_t msecs_time = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
	srand(static_cast<unsigned int>(msecs_time));
}

template <typename T>
void printContainer(T &c, std::string s) {
	std::cout << std::left << std::setw(6) << s << " - ";
	for (typename T::iterator i = c.begin(); i != c.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
}

template <typename T>
void testContainer(T &c, std::string s) {
	

	typename T::iterator it;
	printContainer(c, s);
	int const v = rand() % 24;
	std::cout << "Searching value: " << std::right << std::setw(2) << v << "... "; 
	if ((it = easyfind(c, v)) != c.end())
		std::cout << "Found " << *it << "\n" << std::endl;
	else
		std::cout << "Not found\n" << std::endl;
}

int main() {
	random_seed();
	
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12};

	std::vector<int> vec(arr, arr + (sizeof(arr)/sizeof(int)));
	std::vector<int>::iterator itv;

	std::list<int> lst(arr, arr + (sizeof(arr)/sizeof(int)));
	std::list<int>::iterator itl;

	std::set<int> const st(arr, arr + (sizeof(arr)/sizeof(int)));
	std::set<int>::iterator its;
	
	std::deque<int> deq(arr, arr + (sizeof(arr)/sizeof(int)));
	std::deque<int>::iterator itd;

	testContainer(vec, "Vector");
	testContainer(lst, "List");
	testContainer(lst, "Set");
	testContainer(deq, "Deque");
}
