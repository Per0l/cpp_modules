/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:41:54 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/01 21:14:49 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void handleAttack(ClapTrap &attacker, ClapTrap &victim) {
	std::cout << attacker << victim << std::endl;
	attacker.attack(victim.getName());
	victim.takeDamage(attacker.getDamage());
	std::cout << victim << std::endl;
}

int main(void) {
	std::cout << BBLUE "\n\t---\t\tConstructors tests\t\t---\n" RESET << std::endl;
	ClapTrap c1("clap1");
	ClapTrap c2("clap2");
	ScavTrap s1("scav1");
	ScavTrap s2("scav2");

	std::cout << BBLUE "\n\t---\t\tClapTrap tests\t\t---\n" RESET << std::endl;

	handleAttack(c1, c2);
	c1.beRepaired(4);
	std::cout << c1 << std::endl;
	c2.setDamage(20);
	handleAttack(c2, c1);

	std::cout << BBLUE "\n\t---\t\tScavTrap tests\t\t---\n" RESET << std::endl;

	handleAttack(s1, s2);
	s1.setDamage(200);
	s2.beRepaired(20);
	std::cout << s2 << std::endl;
	s2.guardGate();

	std::cout << BBLUE "\n\t---\t\tMixed tests\t\t---\n" RESET << std::endl;

	handleAttack(c2, s2);

	std::cout << BBLUE "\n\t---\t\tDestructors tests\t\t---\n" RESET << std::endl;
}
