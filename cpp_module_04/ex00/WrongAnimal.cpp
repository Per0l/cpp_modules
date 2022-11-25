/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 00:57:37 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/25 14:13:26 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << GRAY "<WrongAnimal> " RESET << GREEN "constructor" RESET << " called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy): type(copy.type) {}

WrongAnimal::~WrongAnimal() {
	std::cout << GRAY "<WrongAnimal> " RESET << RED "destructor" RESET << " called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &copy) {
	this->type = copy.type;
	return *this;
}

std::string WrongAnimal::getType() const {
	return this->type;
}

void WrongAnimal::setType(std::string type) {
	this->type = type;
}

void WrongAnimal::makeSound() const {
	std::cout << "(Default WrongAnimal::makeSound)" << std::endl;
}
