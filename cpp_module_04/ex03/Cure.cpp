/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:17:46 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/25 14:29:38 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {
	std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(Cure const &copy): AMateria(copy) {}

Cure::~Cure() {}

Cure &Cure::operator=(Cure const &copy) {
	this->_type = copy._type;
	return *this;
}

AMateria* Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at "<< target.getName() << " *" << std::endl;
}
