/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:36:49 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/22 14:42:05 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <literal_value>" << std::endl;
		return 1;
	}
	std::string s(argv[1]);
	try {
		Converter c(s);
		c.print<char>();
		c.print<int>();
		c.print<float>();
		c.print<double>();
	}
	catch(const std::exception& e) {
		std::cout << e.what() << '\n';
		return 1;
	}
	return 0;
}