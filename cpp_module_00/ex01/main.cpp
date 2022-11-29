/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:25:40 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/29 16:25:40 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <iomanip>
#include "PhoneBook.hpp"

int main() {
	PhoneBook	pb;
	std::string	cmd;

	do {
		std::cout << "Command> ";
		std::getline(std::cin, cmd);
		pb.trim(cmd);
		std::cout << std::endl;
		if (cmd.compare("SEARCH") == 0)
			pb.SEARCH();
		else if (cmd.compare("ADD") == 0)
			pb.ADD();
		else if (cmd.compare("EXIT") != 0)
			std::cout << "Available actions: EXIT SEARCH ADD" << std::endl << std::endl;
	} while (cmd.compare("EXIT") != 0);
	return 0;
}
