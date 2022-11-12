/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 00:25:22 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/06 02:07:22 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << BCYAN "<Dog> " RESET << GREEN "constructor" RESET << " called" << std::endl;
	this->setType("Dog");
}

Dog::~Dog() {
	std::cout << BCYAN "<Dog> " RESET << RED "destructor" RESET << " called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "woof" << std::endl;
}
