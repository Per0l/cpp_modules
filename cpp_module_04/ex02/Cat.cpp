/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 00:25:13 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/06 20:23:46 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): brain(new Brain()) {
	std::cout << BBLUE "<Cat> " RESET << GREEN "constructor" RESET << " called" << std::endl;
	this->setType("Cat");
}

Cat::Cat(Cat const &copy): brain(new Brain(*copy.brain)) {
	std::cout << BBLUE "<Cat> " RESET << GREEN "copy constructor" RESET << " called" << std::endl;
	this->setType(copy.type);
}

Cat &Cat::operator=(Cat const &other) {
	if (this != &other) {
		delete this->brain;
		this->brain = new Brain(*other.brain);
		this->Animal::operator=(other);
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << BBLUE "<Cat> " RESET << RED "destructor" RESET << " called" << std::endl;
	delete this->brain;
}

Brain* Cat::getBrain() const {
	return this->brain;
}

void Cat::makeSound() const {
	std::cout << "meow" << std::endl;
}
