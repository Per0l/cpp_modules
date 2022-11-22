/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:13:55 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/22 14:42:38 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP
# include <iostream>
# include <sstream>
# include <iomanip>
# include <limits>
# include <typeinfo>
# include <cstdlib>
# include <cmath>

class Converter
{
private:
    std::string _s;
    double _d;
    float _f;
    int _i;
    char _c;
    enum m_types {CHAR, INT, FLOAT, DOUBLE};
    Converter::m_types _type;
public:
    Converter(std::string s);
    Converter(Converter const &copy);
    ~Converter();

    Converter const &operator=(Converter const &copy);

    class InvalidLiteralException: public std::exception {
        public: const char *what() const throw();
    };

    int	getLiteralType(std::string s);
    int countDigits(std::string s);
    template <typename T> void print();
    int validLiteral();
};

#endif
