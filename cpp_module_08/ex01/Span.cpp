/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:32:01 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/24 17:09:31 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n): _n(n) {}

Span::Span(Span const &copy) {
	*this = copy;
}

Span::~Span() {}

Span const &Span::operator=(Span const &copy) {
	this->_n = copy._n;
	this->_vec = copy._vec;
	return *this;
}

void Span::addNumber(int x) {
	if (this->_vec.size() == this->_n)
		throw StorageFullException();
	this->_vec.push_back(x);
}

int Span::shortestSpan() {
	if (_vec.size() < 2)
		throw NoSpanException();

	std::nth_element(_vec.begin(), _vec.begin()+1, _vec.end());
	int ssmall = *(_vec.begin()+1);

	std::nth_element(_vec.begin(), _vec.end()-2, _vec.end());
	int sbig = *(_vec.end()-2);

	int small = *std::min_element(_vec.begin(), _vec.end());
	int big = *std::max_element(_vec.begin(), _vec.end());

	int d1 = ssmall - small;
	int d2 = big - sbig;
	
	return (d1 < d2) ? d1 : d2;
}

int Span::longestSpan() {
	if (_vec.size() < 2)
		throw NoSpanException();
	int small = *std::min_element(_vec.begin(), _vec.end());
	int big = *std::max_element(_vec.begin(), _vec.end());
	return big - small;
}

const char *Span::StorageFullException::what() const throw() {
	return "Storage full can't add new numbers";
}

const char *Span::NoSpanException::what() const throw() {
	return "Can't find span with less than 2 numbers";
}

void Span::insert(int *first, int *last) {
	if ((last - first) + _vec.size() > _n)
		throw StorageFullException();
	_vec.insert(_vec.end(), first, last);
}

void Span::debug() {
	std::cout << "[Stored numbers: " << _vec.size() << "] - ";
	for (std::vector<int>::iterator i = _vec.begin(); i != _vec.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
}
