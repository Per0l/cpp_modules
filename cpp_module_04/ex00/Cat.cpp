/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 00:25:13 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/06 02:07:14 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << BBLUE "<Cat> " RESET << GREEN "constructor" RESET << " called" << std::endl;
	this->setType("Cat");
}

Cat::~Cat() {
	std::cout << BBLUE "<Cat> " RESET << RED "destructor" RESET << " called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "meow" << std::endl;
}
