/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:41:54 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/01 21:14:53 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
	FragTrap f1("frag1");
	FragTrap f2("frag2");

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

	std::cout << BBLUE "\n\t---\t\tFragTrap tests\t\t---\n" RESET << std::endl;

	handleAttack(f1, f2);
	f1.setDamage(200);
	f2.beRepaired(20);
	std::cout << f2 << std::endl;
	f2.highFivesGuys();

	std::cout << BBLUE "\n\t---\t\tMixed tests\t\t---\n" RESET << std::endl;

	handleAttack(f1, s2);

	std::cout << BBLUE "\n\t---\t\tDestructors tests\t\t---\n" RESET << std::endl;
}
