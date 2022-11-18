/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:26:22 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/18 15:28:36 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

std::string const Intern::names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

Intern::Intern() {}

Intern::Intern(Intern const &copy) {
	*this = copy;
}

Intern::~Intern() {}

Intern const &Intern::operator=(Intern const &copy) {
	(void) copy;
	return *this;
}

Form* Intern::makeForm(std::string form, std::string target) {
	Form* (Intern::*forms[3])(const std::string &) = {
		&Intern::createForm<ShrubberyCreationForm>,
		&Intern::createForm<RobotomyRequestForm>,
		&Intern::createForm<PresidentialPardonForm>
	};
	for (long unsigned int i = 0; i < sizeof(names)/sizeof(names[0]); i++) {
		if (names[i].compare(form) == 0) {
			std::cout << "Intern creates " << form << "." << std::endl;
			return (this->*forms[i])(target);
		}
	}
	std::cout << "Intern error: unknown requested form '" << form << "'." << std::endl;
	return NULL;
}

template <class T>
Form* Intern::createForm(std::string const &target) {
	return new T(target);
}
