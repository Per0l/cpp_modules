/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:50:58 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/25 14:05:57 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

unsigned int const FragTrap::_init_hitpoints = 100;
unsigned int const FragTrap::_init_energy = 100;
unsigned int const FragTrap::_init_damage = 30;

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	std::cout << MAGENTA "<FragTrap> " RESET << UNDERLINE + this->getName() + RESET << GREEN " constructor" RESET << " called" << std::endl;
	this->setHitpoints(this->_init_hitpoints);
	this->setEnergy(this->_init_energy);
	this->setDamage(this->_init_damage);
}

FragTrap::FragTrap(FragTrap const &copy): ClapTrap(copy.getName()) {
	this->setHitpoints(copy.getHitpoints());
	this->setEnergy(copy.getEnergy());
	this->setDamage(copy.getDamage());
}

FragTrap::~FragTrap() {
	std::cout << MAGENTA "<FragTrap> " RESET << UNDERLINE + this->getName() + RESET << RED " destructor" RESET << " called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &copy) {
	this->setName(copy.getName());
	this->setHitpoints(copy.getHitpoints());
	this->setEnergy(copy.getEnergy());
	this->setDamage(copy.getDamage());
	return *this;
}

void FragTrap::attack(std::string const &target) {
	std::cout << MAGENTA "<FragTrap> " RESET << UNDERLINE + this->getName() + RESET << " attack " << UNDERLINE + target + RESET << ", causing " << this->getDamage() << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << MAGENTA "<FragTrap> " RESET << UNDERLINE + this->getName() + RESET << " requests a high five." << std::endl;
}
