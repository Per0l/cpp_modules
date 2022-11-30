/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:50:58 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/30 18:22:16 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << MAGENTA "<FragTrap> " GREEN "default constructor" RESET << " called" << std::endl;
	this->_hitpoints = 100;
	this->_energy = 100;
	this->_damage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	std::cout << MAGENTA "<FragTrap> " RESET << UNDERLINE + this->getName() + RESET << GREEN " constructor" RESET << " called" << std::endl;
	this->_hitpoints = 100;
	this->_energy = 100;
	this->_damage = 30;
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

void FragTrap::highFivesGuys(void) {
	std::cout << MAGENTA "<FragTrap> " RESET << UNDERLINE + this->getName() + RESET << " requests a high five." << std::endl;
}
