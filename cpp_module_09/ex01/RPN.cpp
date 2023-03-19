/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:32:17 by aperol-h          #+#    #+#             */
/*   Updated: 2023/03/19 03:03:56 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

const std::string RPN::_tokens = std::string("+-/*");

RPN::RPN() {}

RPN::RPN(RPN const &copy) {
	*this = copy;
}

RPN::~RPN() {}

RPN const &RPN::operator=(RPN const &copy) {
	this->_s = copy._s;
	return *this;
}

long RPN::evaluate(std::string expr) {
	if (expr.find_first_not_of("0123456789+-/* \t\n\v\f\r") != std::string::npos)
		throw SyntaxErrorException();
	std::string digit;
	for (std::string::iterator it = expr.begin(), end = expr.end(); it != end; ++it) {
		if (isdigit(*it)) {
			digit += *it;
			continue;
		}
		if (!digit.empty()) {
			_s.push(std::atol(digit.c_str()));
			digit = "";
		}
		if (*it == '-' && it+1 != expr.end() && isdigit(*(it+1)))
			digit += *it;
		else if (_tokens.find(*it) != std::string::npos) {
			if (_s.size() < 2)
				throw NotEnoughOperandsException();
			long b = _s.top();
			_s.pop();
			long a = _s.top();
			_s.pop();
			switch (*it)
			{
			case '+':
				_s.push(a + b);
				break;
			case '-':
				_s.push(a - b);
				break;
			case '/':
				_s.push(a / b);
				break;
			case '*':
				_s.push(a * b);
				break;
			}
		}
	}
	if (!digit.empty())
		_s.push(std::atol(digit.c_str()));
	if (_s.size() == 1)
		return _s.top();
	throw TooManyOperandsException();
}

const char *RPN::SyntaxErrorException::what() const throw() {
	return "Error: bad syntax.";
}

const char *RPN::NotEnoughOperandsException::what() const throw() {
	return "Error: not enough operands.";
}

const char *RPN::TooManyOperandsException::what() const throw() {
	return "Error: too many operands.";
}
