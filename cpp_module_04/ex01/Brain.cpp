/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 01:05:32 by aperol-h          #+#    #+#             */
/*   Updated: 2022/12/02 18:24:44 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <cstdlib>
#include <string>

Brain::Brain() {
	std::cout << MAGENTA "<Brain> " RESET << GREEN "constructor" RESET << " called" << std::endl;
	srand(time(0)+rand());
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = '0' + rand() % 10;
	}
}

Brain::Brain(Brain const &copy) {
	std::cout << MAGENTA "<Brain> " RESET << GREEN "copy constructor" RESET << " called" << std::endl;
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = copy.getIdea(i);
}

Brain::~Brain() {
	std::cout << MAGENTA "<Brain> " RESET << RED "destructor" RESET << " called" << std::endl;
}

Brain &Brain::operator=(Brain const &other) {
	if (this != &other) {
		for (int i = 0; i < 100; ++i)
			this->ideas[i] = other.getIdea(i);
	}
	return *this;
}

std::string Brain::getIdea(int index) const {
	return this->ideas[index];
}

void Brain::setIdea(int index, std::string idea) {
	this->ideas[index] = idea;
}
