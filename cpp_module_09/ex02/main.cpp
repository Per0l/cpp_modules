/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:31:49 by aperol-h          #+#    #+#             */
/*   Updated: 2023/03/18 23:45:52 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char*argv[])
{
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " \"number list\"" << std::endl;
		return 1;
	}
	std::string expr;
	if (argc > 2)
		for (int i = 1; i < argc; i++)
			expr += std::string(argv[i]) + " ";
	else
		expr = std::string(argv[1]);

	PmergeMe pme;
	pme.vectorSort(expr);
	std::cout << pme.last_vector_time.count();
}
