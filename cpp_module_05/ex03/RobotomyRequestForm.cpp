/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:57:28 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/18 14:12:24 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("RobotomyRequestForm", target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy): Form(copy) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm const &RobotomyRequestForm::operator=(RobotomyRequestForm const &copy) {
	return *static_cast<RobotomyRequestForm*>(&Form::operator=(copy));
}

void RobotomyRequestForm::run() const {
	struct timeval time_now;
    gettimeofday(&time_now, 0);
    time_t msecs_time = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
	srand(static_cast<unsigned int>(msecs_time));

	std::cout << "Bzzzzzzz... Rizzzzzzz... Drrrrrrr!" << std::endl;
	if (rand() % 2)
		std::cout << this->getTarget() << " has been robotomized." << std::endl;
	else
		std::cout << "Robotomization failed." << std::endl;
}
