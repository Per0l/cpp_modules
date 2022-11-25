/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:41:44 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/25 14:00:21 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name), _hitpoints(10), _energy(10), _damage(0) {
	std::cout << GRAY "<ClapTrap> " RESET << UNDERLINE + this->getName() + RESET << GREEN " constructor" RESET << " called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy): _name(copy._name), _hitpoints(copy._hitpoints), _energy(copy._energy), _damage(copy._damage) {}

ClapTrap::~ClapTrap() {
	std::cout << GRAY "<ClapTrap> " RESET << UNDERLINE + this->getName() + RESET << RED " destructor" RESET << " called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &copy) {
	this->_name = copy._name;
	this->_hitpoints = copy._hitpoints;
	this->_energy = copy._energy;
	this->_damage = copy._damage;
	return *this;
}

std::string ClapTrap::getName() const {
	return this->_name;
}

unsigned int ClapTrap::getHitpoints() const {
	return this->_hitpoints;
}

unsigned int ClapTrap::getEnergy() const {
	return this->_energy;
}

unsigned int ClapTrap::getDamage() const {
	return this->_damage;
}

void ClapTrap::setName(std::string name) {
	this->_name = name;
}

void ClapTrap::setHitpoints(unsigned int amount) {
	this->_hitpoints = amount;
}

void ClapTrap::setEnergy(unsigned int amount) {
	this->_energy = amount;
}

void ClapTrap::setDamage(unsigned int amount) {
	this->_damage = amount;
}

void ClapTrap::attack(std::string const &target) {
	std::cout << GRAY "<ClapTrap> " RESET << UNDERLINE + this->getName() + RESET << " attack " << UNDERLINE + target + RESET << ", causing " << this->_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "> " << UNDERLINE + this->getName() + RESET << " takes " << amount << " points of damage!" << std::endl;
	if (amount > this->_hitpoints)
		this->_hitpoints = 0;
	else
		this->_hitpoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << GRAY "<ClapTrap> " RESET << UNDERLINE + this->getName() + RESET << " repairs " << amount << " hitpoints." << std::endl;
	this->_hitpoints += amount;
}

std::ostream &operator<<(std::ostream &out, ClapTrap const &trap) {
	out << "\n" BG_BLACK "(DEBUG) ";
	out << "Name: " << UNDERLINE + trap.getName() + RESET;
	out << BG_BLACK " | HP: " << trap.getHitpoints();
	out << " | Energy: " << trap.getEnergy();
	out << " | Attack: " << trap.getDamage() << RESET << std::endl;
	return out;
}
