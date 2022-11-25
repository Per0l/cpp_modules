/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 00:25:22 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/25 14:18:30 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << BCYAN "<Dog> " RESET << GREEN "constructor" RESET << " called" << std::endl;
	this->setType("Dog");
}

Dog::Dog(Dog const &copy): Animal(copy) {}

Dog::~Dog() {
	std::cout << BCYAN "<Dog> " RESET << RED "destructor" RESET << " called" << std::endl;
}

Dog &Dog::operator=(Dog const &copy) {
	this->type = copy.type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "woof" << std::endl;
}
