/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:10:41 by aperol-h          #+#    #+#             */
/*   Updated: 2022/08/19 17:11:54 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string *Contact::get_data() {
	return this->data;
}

void Contact::set_data(std::string data[], int idx) {
	this->idx = idx;
	std::copy(data, data + 5, this->data);
}

int Contact::index() {
	return this->idx;
}

bool Contact::exists() {
	for (int i = 0; i < 5; i++)
		if (this->data[i].empty())
			return false;
	return true;
}
