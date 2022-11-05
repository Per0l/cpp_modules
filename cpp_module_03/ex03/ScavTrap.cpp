/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:32:42 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/06 00:14:05 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

unsigned int const ScavTrap::_init_hitpoints = 100;
unsigned int const ScavTrap::_init_energy = 50;
unsigned int const ScavTrap::_init_damage = 20;

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	std::cout << YELLOW "<ScavTrap> " RESET << UNDERLINE + this->getName() + RESET << GREEN " constructor" RESET << " called" << std::endl;
	this->setHitpoints(this->_init_hitpoints);
	this->setEnergy(this->_init_energy);
	this->setDamage(this->_init_damage);
}

ScavTrap::~ScavTrap() {
	std::cout << YELLOW "<ScavTrap> " RESET << UNDERLINE + this->getName() + RESET << RED " destructor" RESET << " called" << std::endl;
}

void ScavTrap::attack(std::string const &target) {
	std::cout << YELLOW "<ScavTrap> " RESET << UNDERLINE + this->getName() + RESET << " attack " << UNDERLINE + target + RESET << ", causing " << this->getDamage() << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << YELLOW "<ScavTrap> " RESET << UNDERLINE + this->getName() + RESET << " have entered in gate keeper mode." << std::endl;
}
