/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:02:25 by aperol-h          #+#    #+#             */
/*   Updated: 2022/10/25 18:43:49 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
private:
    int                 _value;
    static const int    _bits;
public:
    Fixed();
    Fixed(const Fixed &copy);

    Fixed(const int value);
    Fixed(const float value);
    ~Fixed();

    Fixed &operator=(const Fixed &copy);

    int getRawBits(void) const;
	void setRawBits(const int raw);

    float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &fixed);

#endif
