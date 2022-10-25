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
    Fixed(Fixed const &copy);
    Fixed(int const value);
    Fixed(float const value);
    ~Fixed();

    Fixed &operator=(Fixed const &copy);

    int getRawBits(void) const;
	void setRawBits(int const raw);

    float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &fixed);

#endif
