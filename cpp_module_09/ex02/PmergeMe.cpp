/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:32:25 by aperol-h          #+#    #+#             */
/*   Updated: 2023/03/19 01:55:04 by aperol-h         ###   ########.fr       */
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

template <typename T>
void	PmergeMe::_parse(T &c, std::string input) {
	std::istringstream ss(input);
	for (std::string line; std::getline(ss, line, ' '); ) {
		if (line.length() > 0)
	        c.push_back(std::stoi(line));
	}
}

void    PmergeMe::_vectorParse(std::string input) {
	_parse(_v, input);
}
void    PmergeMe::_dequeParse(std::string input) {
	_parse(_d, input);
}

template <typename T>
void PmergeMe::_printContainer(T begin, T end) {
	for (T it = begin; it < end; it++)
		std::cout << *it << " ";
}

void PmergeMe::printVector() {
	this->_printContainer(_v.begin(), _v.end());
}

void PmergeMe::printDeque() {
	this->_printContainer(_d.begin(), _d.end());
}

template <typename T>
void PmergeMe::_insertionSort(T &c) {
	for (size_t i = 0; i < c.size(); i++)
		std::rotate(std::upper_bound(c.begin(), c.begin()+i, c[i]), c.begin()+i, c.begin()+i+1);
}

template <typename T>
void mergeSort(T &c) {
    if (c.end() - c.begin() > 13) {
        typename T::iterator mid = (c.begin() + c.end()) / 2;
		T left(c.begin(), mid);
		T right(mid, c.end());
        mergeSort(left);
        mergeSort(right);
        int RIDX = 0;
		int LIDX = 0;
		for (int i = c.begin(); i < c.end() - c.begin() + 1; i++) {
			if (RIDX == right.end()) {
				c[i] = left[LIDX];
				LIDX++;
			} else if (LIDX == left.end()) {
				c[i] = right[RIDX];
				RIDX++;
			} else if (right[RIDX] > left[LIDX]) {
				c[i] = left[LIDX];
				LIDX++;
			} else {
				c[i] = right[RIDX];
				RIDX++;
			}
		}
    } else {
        _insertionSort(c);
    }
}

template <typename T>
void PmergeMe::_sort(T &c, std::string input) {
	std::chrono::steady_clock::time_point start = std::chrono::high_resolution_clock::now();
	this->_parse(c, input);
	this->_insertionSort(c);
	std::chrono::steady_clock::time_point stop = std::chrono::high_resolution_clock::now();
	time_elpased = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
}

void PmergeMe::vectorSort(std::string input) {
	_sort(_v, input);
}

void PmergeMe::dequeSort(std::string input) {
	_sort(_d, input);
}
