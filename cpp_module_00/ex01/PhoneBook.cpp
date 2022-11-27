/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:53:15 by aperol-h          #+#    #+#             */
/*   Updated: 2022/08/19 17:30:49 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->fields[0] = "Firs Name";
	this->fields[1] = "Last Name";
	this->fields[2] = "Nickname";
	this->fields[3] = "Phone Number";
	this->fields[4] = "Darkest Secret";
	this->idx = 0;
}

void PhoneBook::add(std::string data[]) {
	this->contacts[this->idx].set_data(data, this->idx);
	this->idx = (this->idx + 1) % 8;
}

void PhoneBook::ADD() {
	std::string	data[5];
	std::string	line;

	for (int i = 0; i < 5; i++) {
		std::cout << this->fields[i] << ": ";
		std::getline(std::cin, data[i]);
		if (data[i].empty()) {
			std::cout << "Error: Contact can't have empty fields." << std::endl;
			return;
		}
	}
	std::cout << std::endl;
	this->add(data);
}

void PhoneBook::SEARCH() {
	for (int i = 0; i < 8; i++) {
		Contact	*current = &this->contacts[i];
		if (!current->exists())
			continue;

		std::string	tmp[4];
		std::string	*contact_data = current->get_data();
		tmp[0] = SSTR(current->index());
		std::copy(contact_data, contact_data+3, tmp+1);

		std::cout << std::right;
		for (int j = 0; j < 4; j++) {
			if (tmp[j].size() > 10)
				tmp[j] = tmp[j].substr(0, 9) + ".";
			std::cout << std::setw(10) << tmp[j] << "|";
		}
		std::cout << std::endl;
	}
	int			inp;
	std::string line;
	std::cout << std::endl << "Enter index of desired entry: ";
	std::getline(std::cin, line);
	std::cout << std::endl;
	std::istringstream tmp( line );
	tmp >> inp;
	if (tmp && inp >= 0 && inp <= 8 && this->contacts[inp].exists()) {
		std::string	*data = this->contacts[inp].get_data();
		for (int i = 0; i < 5; i++)
			std::cout << this->fields[i] << ": " << data[i] << std::endl;
		
		std::cout << std::endl;
	}
}
