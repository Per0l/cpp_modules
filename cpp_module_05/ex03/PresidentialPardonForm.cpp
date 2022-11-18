/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:59:43 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/18 14:14:41 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("PresidentialPardonForm", target, 25, 5) { Form::classes = "b";}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy): Form(copy) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm const &PresidentialPardonForm::operator=(PresidentialPardonForm const &copy) {
	return *static_cast<PresidentialPardonForm*>(&Form::operator=(copy));
}

void PresidentialPardonForm::run() const {
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
