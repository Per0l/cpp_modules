/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:45:11 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/25 14:28:17 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type): _type(type) {
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(AMateria const &copy): _type(copy._type) {}

AMateria::~AMateria() {
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &copy) {
	this->_type = copy._type;
	return *this;
}

std::string const & AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "AMateria abstractly used on " << target.getName() << std::endl;
}
