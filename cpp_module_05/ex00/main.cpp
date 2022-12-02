/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:27:58 by aperol-h          #+#    #+#             */
/*   Updated: 2022/12/02 20:53:02 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	Bureaucrat b("HighB", 10);
	for (int i = 0; i < 10; i++) {
		std::cout << b << std::endl;
		try {
			b.incrementGrade();
		}
		catch (Bureaucrat::GradeTooHighException &e) {
			std::cout << "Exception caught: '" << e.what() << "'" << std::endl;
			std::cout << b << std::endl;
		}
	}
	Bureaucrat b2("LowB", 141);
	for (int i = 0; i < 10; i++) {
		std::cout << b2 << std::endl;
		try {
			b2.decrementGrade();
		}
		catch (Bureaucrat::GradeTooLowException &e) {
			std::cout << "Exception caught: '" << e.what() << "'" << std::endl;
			std::cout << b2 << std::endl;
		}
	}
	try {
		Bureaucrat b3("LowB", 151);
	}
	catch (std::exception &e) {
    	std::cout << "Exception caught: '" << e.what() << "'" << std::endl;
    }
	try {
		Bureaucrat b3("LowB", 0);
	}
	catch (std::exception &e) {
    	std::cout << "Exception caught: '" << e.what() << "'" << std::endl;
    }
}
