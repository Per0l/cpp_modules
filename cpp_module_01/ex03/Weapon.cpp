/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:49:01 by aperol-h          #+#    #+#             */
/*   Updated: 2022/10/16 03:47:18 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type)
{

}

Weapon::~Weapon()
{

}

const std::string &Weapon::getType()
{
	return (this->_type);
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}