/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:30:55 by aperol-h          #+#    #+#             */
/*   Updated: 2023/03/18 15:30:57 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

class BitcoinExchange
{
private:

public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const &copy);
    ~BitcoinExchange();

    BitcoinExchange const &operator=(BitcoinExchange const &copy);
};

#endif
