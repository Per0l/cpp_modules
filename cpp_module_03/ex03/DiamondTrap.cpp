/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:19:05 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/25 14:08:32 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name+"_clap_name"), FragTrap(name), ScavTrap(name), _name(name) {
	std::cout << CYAN "<DiamondTrap> " RESET << UNDERLINE + this->_name + RESET << GREEN " constructor" RESET << " called" << std::endl;
	
	this->setHitpoints(FragTrap::_init_hitpoints);
	this->setEnergy(ScavTrap::_init_energy);
	this->setDamage(FragTrap::_init_damage);
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy): ClapTrap(copy._name+"_clap_name"), FragTrap(copy._name), ScavTrap(copy._name), _name(copy._name) {
	this->setHitpoints(copy.getHitpoints());
	this->setEnergy(copy.getEnergy());
	this->setDamage(copy.getDamage());
}

DiamondTrap::~DiamondTrap() {
	std::cout << CYAN "<DiamondTrap> " RESET << UNDERLINE + this->getName() + RESET << RED " destructor" RESET << " called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &copy) {
	this->setName(copy.getName());
	this->setHitpoints(copy.getHitpoints());
	this->setEnergy(copy.getEnergy());
	this->setDamage(copy.getDamage());
	return *this;
}

void DiamondTrap::whoAmI() {
	std::cout << "Name: " << UNDERLINE + this->_name + RESET << " | clapTrapName: " <<  UNDERLINE + ClapTrap::getName() + RESET << std::endl;
}

std::string DiamondTrap::getName() const {
	return this->_name;
}

void DiamondTrap::attack(std::string const &target) {
	ScavTrap::attack(target);
}
