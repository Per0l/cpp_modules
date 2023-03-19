/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:31:10 by aperol-h          #+#    #+#             */
/*   Updated: 2023/03/19 03:21:29 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

std::time_t extractDate(const std::string& s) {
    std::istringstream is(s);
	int y, m, d;
    char delimiter;
    if (is >> y >> delimiter >> m >> delimiter >> d) {
        struct tm t;
		memset(&t, 0, sizeof(struct tm));
        t.tm_mday = d;
        t.tm_mon = m - 1;
        t.tm_year = y - 1900;
        t.tm_isdst = -1;
        time_t when = mktime(&t);
        const struct tm *norm = localtime(&when);

		struct std::tm dt;
		memset(&dt, 0, sizeof(struct tm));
		std::istringstream date(s);
		date >> std::get_time(&dt, "%Y-%m-%d");
		std::time_t epoch = std::mktime(&dt);
		
        return (norm->tm_mday == d    &&
                norm->tm_mon  == m - 1 &&
                norm->tm_year == y - 1900) ? epoch : -1;
    }
    return -1;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " input.txt" << std::endl;
		return 1;
	}
	std::ifstream	data;
	BitcoinExchange be;
	try {
		data.open(argv[1]);
		if (!data.is_open())
			throw BitcoinExchange::FileErrorException();
		be.loadData("./data.csv");
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
		return 1;
	}
	
	std::string s;
	std::string delimiter = "|";
	std::getline(data, s);
	while (std::getline(data, s)) {
		size_t dpos = s.find(delimiter);
		if (dpos == s.npos || dpos+1 >= s.length()) {
			std::cerr << "Error: bad input => " << s << std::endl;
			continue;
		}
		s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end());
		dpos = s.find(delimiter);
		std::time_t date = extractDate(s.substr(0, dpos));
		if (date == -1) {
			std::cerr << "Error: bad input => " << s.substr(0, dpos) << std::endl;
			continue;
		}
		float value;
		std::istringstream(s.substr(dpos+1, s.npos)) >> value;
		if (value < 0 || value > 1000) {
			std::cerr << "Error: invalid value => " << value << std::endl;
			continue;
		}
		std::cout << s.substr(0, dpos) << " => " << value << " = " << value * be.getPriceAt(date) << "\n";
	}
	data.close();
}
