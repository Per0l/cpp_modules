/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 00:25:13 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/30 21:57:00 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): brain(new Brain()) {
	std::cout << BBLUE "<Cat> " RESET << GREEN "constructor" RESET << " called" << std::endl;
	this->setType("Cat");
}

Cat::Cat(Cat const &copy): Animal(copy), brain(new Brain(*copy.brain)) {
	std::cout << BBLUE "<Cat> " RESET << GREEN "copy constructor" RESET << " called" << std::endl;
}

Cat::~Cat() {
	std::cout << BBLUE "<Cat> " RESET << RED "destructor" RESET << " called" << std::endl;
	if (this->brain)
		delete this->brain;
}

Cat &Cat::operator=(Cat const &other) {
	if (this != &other) {
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain);
		this->Animal::operator=(other);
	}
	return (*this);
}

Brain* Cat::getBrain() const {
	return this->brain;
}

void Cat::makeSound() const {
	std::cout << "meow" << std::endl;
}
