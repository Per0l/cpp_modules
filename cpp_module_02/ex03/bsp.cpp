/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:04:27 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/30 00:58:46 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(const Point p0, const Point p1, const Point p2, const Point p) {
	Fixed s = (p0.getX() - p2.getX()) * (p.getY() - p2.getY()) - (p0.getY() - p2.getY()) * (p.getX() - p2.getX());
    Fixed t = (p1.getX() - p0.getX()) * (p.getY() - p0.getY()) - (p1.getY() - p0.getY()) * (p.getX() - p0.getX());

    if ((s < 0) != (t < 0) && s != 0 && t != 0)
        return false;

    Fixed d = (p2.getX() - p1.getX()) * (p.getY() - p1.getY()) - (p2.getY() - p1.getY()) * (p.getX() - p1.getX());
    return d != 0 && (d < 0) == (s + t <= 0);
}
