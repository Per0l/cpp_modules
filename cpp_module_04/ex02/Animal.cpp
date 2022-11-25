/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 00:23:57 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/25 14:12:21 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("Animal") {
	std::cout << GRAY "<Animal> " RESET << GREEN "constructor" RESET << " called" << std::endl;
}

Animal::Animal(Animal const &copy): type(copy.type) {}

Animal::~Animal() {
	std::cout << GRAY "<Animal> " RESET << RED "destructor" RESET << " called" << std::endl;
}

Animal &Animal::operator=(Animal const &copy) {
	this->type = copy.type;
	return *this;
}

std::string Animal::getType() const {
	return this->type;
}

void Animal::setType(std::string type) {
	this->type = type;
}

void Animal::makeSound() const {
	std::cout << "(Default Animal::makeSound)" << std::endl;
}
