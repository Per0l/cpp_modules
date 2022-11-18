/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:27:58 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/13 20:44:41 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	Bureaucrat b("TestBureaucrat", 11);
	Form f("TestForm", 10, 10);
	b.signForm(f);
	std::cout << f << std::endl;
	b.incrementGrade();
	b.signForm(f);
	std::cout << f << std::endl;
}