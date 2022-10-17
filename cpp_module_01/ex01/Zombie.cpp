/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:43:25 by aperol-h          #+#    #+#             */
/*   Updated: 2022/10/17 02:42:29 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	this->_name = name;
	std::cout << "Zombie " << this->_name << " created" << std::endl;
}

Zombie::Zombie() {
	this->_name = "null";
	std::cout << "Zombie " << this->_name << " created" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Zombie " << this->_name << " destroyed" << std::endl;
}

void Zombie::announce() {
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	this->_name = name;
}
