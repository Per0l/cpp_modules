/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 23:49:57 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/30 01:07:04 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
private:
    const Fixed x;
    const Fixed y;
public:
    Point();
    Point(const float x, const float y);
    Point(Point const &copy);
    ~Point();

    Point const &operator=(Point const &copy);

    const Fixed getX() const;
    const Fixed getY() const;
};

bool bsp(const Point p0, const Point p1, const Point p2, const Point p);

#endif
