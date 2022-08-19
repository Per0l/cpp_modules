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
	this->idx = 0;
}

void PhoneBook::add(std::string data[]) {
	this->contacts[this->idx % 8].set_data(data, this->idx);
	this->idx++;
}

void PhoneBook::ADD() {
	std::string	data[5];
	int			i = 0;

	std::cout << "First Name: ", std::cin >> data[i++];
	std::cout << "Last Name: ", std::cin >> data[i++];
	std::cout << "Nickname: ", std::cin >> data[i++];
	std::cout << "Phone Number: ", std::cin >> data[i++];
	std::cout << "Darkest Secret: ", std::cin >> data[i++];
	this->add(data);
}

void PhoneBook::SEARCH() {
	for (int i = 0; i < 8; i++) {
		Contact	*current = &this->contacts[i];
		if (!current->exists())
			continue;
		std::string	*contact_data = current->get_data();
		std::string	tmp[4];
		tmp[0] = std::to_string(current->index());
		std::copy(contact_data, contact_data+3, tmp+1);
		for (int j = 0; j < 4; j++) {
			std::cout << tmp[j] << " ";
		}
		std::cout << std::endl;
	}
}
