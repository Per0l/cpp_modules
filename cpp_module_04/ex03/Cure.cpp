/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:17:46 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/30 21:43:31 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {}

Cure::Cure(Cure const &copy): AMateria(copy) {}

Cure::~Cure() {}

Cure &Cure::operator=(Cure const &copy) {
	(void)copy;
	return *this;
}

AMateria* Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals "<< target.getName() << "'s wounds *" << std::endl;
}
