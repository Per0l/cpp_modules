/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:16:47 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/30 21:43:37 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {}

Ice::Ice(Ice const &copy): AMateria(copy) {}

Ice::~Ice() {}

Ice &Ice::operator=(Ice const &copy) {
	(void)copy;
	return *this;
}

AMateria* Ice::clone() const {
	return new Ice();
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at "<< target.getName() << " *" << std::endl;
}
