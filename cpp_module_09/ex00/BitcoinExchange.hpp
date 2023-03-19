/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:30:55 by aperol-h          #+#    #+#             */
/*   Updated: 2023/03/19 02:53:58 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <fstream>
# include <sstream>
# include <map>

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
};

#endif
