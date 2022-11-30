/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 00:23:15 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/30 20:15:00 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	Animal *Animals[10];
	for (int i = 0; i < 5; ++i)
			Animals[i] = new Dog();

	for (int i = 5; i < 10; ++i)
		Animals[i] = new Cat();

	std::cout << "DEEP COPY!!" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	Dog copy;
	copy = *dynamic_cast<Dog*>(Animals[4]);
	for (int i = 0; i < 10; ++i) {
		std::cout << copy.getBrain()->getIdea(i) << "    ";
		std::cout << Animals[4]->getBrain()->getIdea(i) << std::endl;
	}
	std::cout << copy.getType() << "\n-----------------------------" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	Cat copy2(*dynamic_cast<Cat*>(Animals[7]));
	for (int i = 0; i < 10; ++i) {
		std::cout << copy2.getBrain()->getIdea(i) << "    ";
		std::cout << Animals[7]->getBrain()->getIdea(i) << std::endl;
	}
	std::cout << copy2.getType() << "\n-----------------------------" << std::endl;
	for (int j = 0; j < 9; j+=2) {
		std::cout << "-----------------------------" << std::endl;
		for (int i = 0; i < 10; ++i) {
			std::cout << Animals[j]->getBrain()->getIdea(i) << "    ";
			std::cout << Animals[j+1]->getBrain()->getIdea(i) << std::endl;
		}
		std::cout << "-----------------------------" << std::endl;
	}
	
	for (int i = 0; i < 10; ++i)
		delete Animals[i];
}
