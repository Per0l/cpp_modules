/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:08:47 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/30 21:42:49 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {
	IMateriaSource* tsrc = new MateriaSource();

	tsrc->learnMateria(new Ice());
	tsrc->learnMateria(new Cure());

	IMateriaSource* src = new MateriaSource(*dynamic_cast<MateriaSource*>(tsrc));

	ICharacter* me = new Character("me");

	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* test = new Character("bob");
	ICharacter* bob = new Character(*dynamic_cast<Character*>(test));

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);
	me->use(-3, *bob);
	
	delete bob;
	delete me;
	delete src;
	delete tsrc;
	delete test;
	return 0;
}
