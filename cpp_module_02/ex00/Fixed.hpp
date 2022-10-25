/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:02:25 by aperol-h          #+#    #+#             */
/*   Updated: 2022/10/25 18:44:14 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
private:
    int                 _value;
    static const int    _bits;
public:
    Fixed();
    Fixed(Fixed const &copy);
    Fixed &operator=(Fixed const &copy);

    ~Fixed();

    int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
