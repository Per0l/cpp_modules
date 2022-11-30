/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:50:13 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/30 21:47:48 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): _name("(null)"), _inventory() {}

Character::Character(std::string name): _name(name), _inventory() {}

Character::Character(Character const &copy): _name(copy._name), _inventory() {
	for (int i = 0; i < 4; i++) {
		if (copy._inventory[i])
			this->_inventory[i] = copy._inventory[i]->clone();
	}
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

Character const	&Character::operator=(Character const &copy) {
	if (this != &copy) {
		this->_name = copy._name;
		for (int i = 0; i < 4; i++) {
			if (this->_inventory[i])
				delete this->_inventory[i];
			this->_inventory[i] = NULL;
			if (copy._inventory[i])
				this->_inventory[i] = copy._inventory[i]->clone();
		}
	}
	return *this;
}

std::string const & Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx <= 3)
		this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3)
		return;
	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
}
