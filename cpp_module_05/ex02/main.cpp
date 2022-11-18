/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:27:58 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/15 18:03:27 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat b("TestBureaucrat", 146);
	ShrubberyCreationForm f("ShrubberyTarget");
	RobotomyRequestForm rf("RobotomyTarget");
	PresidentialPardonForm pf("PresidentialTarget");
	std::cout << b << std::endl;
	b.signForm(f);
	std::cout << f << std::endl;
	b.executeForm(f);
	b.incrementGrade();
	std::cout << b << std::endl;
	b.signForm(f);
	std::cout << f << std::endl;
	b.executeForm(f);
	b.setGrade(137);
	std::cout << b << std::endl;
	b.executeForm(f);
	
	b.setGrade(1);
	b.signForm(rf);
	b.executeForm(rf);
	b.signForm(pf);
	b.executeForm(pf);
}