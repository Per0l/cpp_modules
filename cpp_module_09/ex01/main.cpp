/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:31:34 by aperol-h          #+#    #+#             */
/*   Updated: 2023/03/19 02:54:49 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main(int argc, char*argv[])
{
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " \"RPN Exprexion\"" << std::endl;
		return 1;
	}
	std::string expr;
	if (argc > 2)
		for (int i = 1; i < argc; i++)
			expr += std::string(argv[i]) + " ";
	else
		expr = std::string(argv[1]);

	try
	{
		RPN rpn;
		std::cout << rpn.evaluate(expr) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
}
