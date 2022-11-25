/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 00:57:31 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/25 14:17:03 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << BBLUE "<WrongCat> " RESET << GREEN "constructor" RESET << " called" << std::endl;
	this->setType("WrongCat");
}

WrongCat::WrongCat(WrongCat const &copy): WrongAnimal(copy) {}

WrongCat::~WrongCat() {
	std::cout << BBLUE "<WrongCat> " RESET << RED "destructor" RESET << " called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &copy) {
	this->type = copy.type;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "wrong meow" << std::endl;
}
