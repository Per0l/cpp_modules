/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:32:25 by aperol-h          #+#    #+#             */
/*   Updated: 2023/03/19 03:05:04 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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

const char *PmergeMe::NegativeNumberErrorException::what() const throw() {
	return "Error: negative number.";
}

const char *PmergeMe::InvalidArgumentErrorException::what() const throw() {
	return "Error: invalid argument.";
}

template <typename T>
void	PmergeMe::_parse(T &c, std::string input) {
	std::istringstream ss(input);
	for (std::string line; std::getline(ss, line, ' '); ) {
		if (line.length() > 0) {
			try {
				int n = std::stoi(line);
				if (n < 0)
					throw NegativeNumberErrorException();
				c.push_back(n);
  			}
			catch (const std::invalid_argument& ia) {
				throw InvalidArgumentErrorException();
			}
		}
	}
}

void    PmergeMe::_vectorParse(std::string input) {
	_parse(_v, input);
}
void    PmergeMe::_dequeParse(std::string input) {
	_parse(_d, input);
}

template <typename T>
size_t PmergeMe::_printContainer(T &c) {
	size_t size = 0;
	for (typename T::iterator it = c.begin(); it < c.end(); it++, size++)
		std::cout << *it << " ";
	std::cout << std::endl;
	return (size);
}

void PmergeMe::printVector() {
	this->_printContainer(_v);
}

void PmergeMe::printDeque() {
	this->_printContainer(_d);
}

template <typename T>
void PmergeMe::_insertionSort(T &c) {
	for (size_t i = 0; i < c.size(); i++)
		std::rotate(std::upper_bound(c.begin(), c.begin()+i, c[i]), c.begin()+i, c.begin()+i+1);
}

template <typename T>
void PmergeMe::_mergeSort(T &c) {
	const int size = c.size();
    if (size > 13) {
        typename T::iterator mid = c.begin() + size / 2;
		T left(c.begin(), mid);
		T right(mid, c.end());
        _mergeSort(left);
        _mergeSort(right);
        typename T::iterator RIDX = right.begin();
		typename T::iterator LIDX = left.begin();
		for (typename T::iterator i = c.begin(); i < c.end(); i++) {
			if (RIDX == right.end())
				*i = *LIDX++;
			else if (LIDX == left.end())
				*i = *RIDX++;
			else if (*RIDX > *LIDX)
				*i = *LIDX++;
			else
				*i = *RIDX++;
		}
		return;
    }
    _insertionSort(c);
}

template <typename T>
void PmergeMe::_sort(T &c, std::string input) {
	std::chrono::steady_clock::time_point start = std::chrono::high_resolution_clock::now();
	this->_parse(c, input);
	this->_mergeSort(c);
	std::chrono::steady_clock::time_point stop = std::chrono::high_resolution_clock::now();
	time_elpased = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
}

void PmergeMe::vectorSort(std::string input) {
	_sort(_v, input);
}

void PmergeMe::dequeSort(std::string input) {
	_sort(_d, input);
}
