/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:08:30 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/29 21:03:43 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen() {
	void (Karen::*funcs_ptr[4])(void) = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	std::copy(funcs_ptr, funcs_ptr+4, this->funcs_ptr);
	std::copy(levels, levels+4, this->levels);
}

Karen::~Karen() {

}

void	Karen::debug(void) {
	std::cout << "[ DEBUG ] - ";
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. ";
	std::cout << "I just love it!" << std::endl;
}

void	Karen::info(void) {
	std::cout << "[ INFO ] - ";
	std::cout << "I cannot believe adding extra bacon cost more money. ";
	std::cout << "You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Karen::warning(void) {
	std::cout << "[ WARNING ] - ";
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming here for years and you just started working here last month." << std::endl;
}

void	Karen::error(void) {
	std::cout << "[ ERROR ] - ";
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void	Karen::complain(std::string level) {
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*funcs_ptr[i])();
			return;
		}
	}
}

std::string *Karen::getLevels() {
	return this->levels;
}
