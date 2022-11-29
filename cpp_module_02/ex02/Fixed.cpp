/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:02:20 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/25 13:57:56 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed(): _value(0) {}

Fixed::Fixed(const int value): _value(value << _bits) {} 

Fixed::Fixed(const float value): _value(roundf(value * (1 << _bits))) {}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &copy) {
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy) {
	this->_value = copy._value;
	return *this;
}

bool Fixed::operator>(const Fixed &other) const {
	return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const {
	return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const {
	return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const {
	return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const {
	return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const {
	return (this->getRawBits() != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed	res(*this);

	res.setRawBits(this->getRawBits() + other.getRawBits());
	return (res);
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed	res(*this);

	res.setRawBits(this->getRawBits() - other.getRawBits());
	return (res);
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed	res(*this);
	long	old1, old2;

	old1 = ((long)this->getRawBits());
	old2 = ((long)other.getRawBits());
	res.setRawBits((old1 * old2) / (1 << Fixed::_bits));
	return (res);
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed	res(*this);
	long	old1, old2;

	old1 = ((long)this->getRawBits());
	old2 = ((long)other.getRawBits());
	res.setRawBits((old1 * (1 << Fixed::_bits)) / old2);
	return (res);
}

Fixed Fixed::operator++() {
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed	old(*this);

	operator++();
	return (old);
}

Fixed Fixed::operator--() {
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed	old(*this);

	operator--();
	return (old);
}


int Fixed::getRawBits(void) const {
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

float	Fixed::toFloat(void) const {
	return (float) this->_value / (1 << _bits);
}

int	Fixed::toInt(void) const {
	return this->_value >> _bits;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a > b)
		return (b);
	return (a);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a > b)
		return (b);
	return (a);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a > b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return (a);
	return (b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}
