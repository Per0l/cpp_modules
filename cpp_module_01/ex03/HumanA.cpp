/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 03:12:00 by aperol-h          #+#    #+#             */
/*   Updated: 2022/10/17 02:42:55 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon) {
	//std::cout << "HumanA " << name << " created with " << weapon.getType() << std::endl;
}

HumanA::~HumanA() {

}

void HumanA::attack() {
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}
