/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 00:25:22 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/25 14:24:12 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): brain(new Brain()) {
	std::cout << BCYAN "<Dog> " RESET << GREEN "constructor" RESET << " called" << std::endl;
	this->setType("Dog");
}

Dog::Dog(Dog const &copy): Animal(copy), brain(new Brain(*copy.brain)) {
	std::cout << BCYAN "<Dog> " RESET << GREEN "copy constructor" RESET << " called" << std::endl;
}

Dog::~Dog() {
	std::cout << BCYAN "<Dog> " RESET << RED "destructor" RESET << " called" << std::endl;
	delete this->brain;
}

Dog &Dog::operator=(Dog const &other) {
	if (this != &other) {
		delete this->brain;
		this->brain = new Brain(*other.brain);
		this->Animal::operator=(other);
	}
	return (*this);
}

Brain* Dog::getBrain() const {
	return this->brain;
}

void Dog::makeSound() const {
	std::cout << "woof" << std::endl;
}
