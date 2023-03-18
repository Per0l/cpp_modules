/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:32:25 by aperol-h          #+#    #+#             */
/*   Updated: 2023/03/18 23:47:19 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &copy) {
	*this = copy;
}

PmergeMe::~PmergeMe() {}

PmergeMe const &PmergeMe::operator=(PmergeMe const &copy) {
	this->_v = copy._v;
	this->_d = copy._d;
	return *this;
}

void    PmergeMe::_vectorParse(std::string input) {
	std::istringstream ss(input);
	for (std::string line; std::getline(ss, line, ' '); ) {
		if (line.length() > 0)
	        this->_v.push_back(std::stoi(line));
	}
	
}
void    PmergeMe::_dequeParse(std::string input) {
	std::istringstream ss(input);
	for (std::string line; std::getline(ss, line, ' '); ) {
		if (line.length() > 0)
	        this->_v.push_back(std::stoi(line));
	}
}

void PmergeMe::vectorSort(std::string input) {
	std::chrono::steady_clock::time_point start = std::chrono::high_resolution_clock::now();
	this->_vectorParse(input);
	std::chrono::steady_clock::time_point stop = std::chrono::high_resolution_clock::now();
	last_vector_time = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
}

void PmergeMe::dequeSort(std::string input) {
	std::chrono::steady_clock::time_point start = std::chrono::high_resolution_clock::now();
	this->_dequeParse(input);
	std::chrono::steady_clock::time_point stop = std::chrono::high_resolution_clock::now();
	last_deque_time = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
}
