/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:31:03 by aperol-h          #+#    #+#             */
/*   Updated: 2023/03/19 02:52:46 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void BitcoinExchange::loadData(std::string datafile) {
	std::ifstream	data;
	data.open(datafile);
	if (!data.is_open())
		throw FileErrorException();
	std::string s;
	std::string delimiter = ",";
	while (std::getline(data, s)) {
		s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end());
		size_t dpos = s.find(delimiter);
		if (dpos == s.npos || dpos+1 >= s.length())
			continue;
		std::istringstream date(s.substr(0, dpos));
		float value;
		std::istringstream(s.substr(dpos+1, s.npos)) >> value;
		struct std::tm dt;
		memset(&dt, 0, sizeof(struct tm));
		date >> std::get_time(&dt, "%Y-%m-%d");
		std::time_t t = std::mktime(&dt);
		_data[t] = value;
	}
	data.close();
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy) {
	*this = copy;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange const &BitcoinExchange::operator=(BitcoinExchange const &copy) {
	this->_data = copy._data;
	return *this;
}

float BitcoinExchange::getPriceAt(std::time_t atTime) const
{
	std::map<std::time_t, float>::const_iterator it = _data.lower_bound(atTime);
	if (it == _data.end())
		it = std::prev(it);
	if (it != _data.begin() && (std::abs(it->first - atTime) > std::abs(std::prev(it)->first - atTime)))
		return std::prev(it)->second;
	return it->second;
}

const char *BitcoinExchange::FileErrorException::what() const throw() {
	return "Error: could not open file.";
}


