/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:30:55 by aperol-h          #+#    #+#             */
/*   Updated: 2023/03/18 20:23:46 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <string>
# include <fstream>
# include <sstream>
# include <string>
# include <iostream>
# include <algorithm>
# include <map>
# include <cmath>

class BitcoinExchange
{
private:
    std::map<std::time_t, float> _data;
public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const &copy);
    ~BitcoinExchange();

    BitcoinExchange const &operator=(BitcoinExchange const &copy);

    class FileErrorException: public std::exception {
        public: const char *what() const throw();
    };
    
    void loadData(std::string database);
    float getPriceAt(std::time_t atTime) const;
    bool isDateValid(std::tm date) const;
};

#endif
