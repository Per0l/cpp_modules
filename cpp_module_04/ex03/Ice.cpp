/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:16:47 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/25 14:30:01 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {
	std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(Ice const &copy): AMateria(copy) {}

Ice::~Ice() {}

Ice &Ice::operator=(Ice const &copy) {
	this->_type = copy._type;
	return *this;
}

AMateria* Ice::clone() const {
	return new Ice();
}

void Ice::use(ICharacter& target) {
	std::cout << "* heals "<< target.getName() << "'s wounds *" << std::endl;
}
