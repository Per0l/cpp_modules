/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:06:37 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/30 21:49:06 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): _inventory() {}

MateriaSource::MateriaSource(MateriaSource const &copy): _inventory() {
	for (int i = 0; i < 4; i++) {
		if (copy._inventory[i] != NULL)
			this->_inventory[i] = copy._inventory[i]->clone();
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource const &copy) {
	if (this == &copy)
		return *this;
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = NULL;
		if (copy._inventory[i] != NULL)
			this->_inventory[i] = copy._inventory[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] && this->_inventory[i]->getType() == type)
			return this->_inventory[i]->clone();
	}
	return NULL;
}
