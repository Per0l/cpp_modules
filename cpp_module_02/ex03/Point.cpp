/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 23:50:02 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/30 01:07:07 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0) {}

Point::Point(const float x, const float y): x(Fixed(x)), y(Fixed(y)) {}

Point::Point(Point const &copy) {
	*this = copy;
}

Point::~Point() {}

Point const &Point::operator=(Point const &copy) {
	if (this != &copy) {
        const_cast<Fixed&>(this->x) = copy.x;
        const_cast<Fixed&>(this->y) = copy.y;
    }
	return *this;
}

const Fixed Point::getX() const {
	return this->x;
}

const Fixed Point::getY() const {
	return this->y;
}
