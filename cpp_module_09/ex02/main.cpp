/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:31:49 by aperol-h          #+#    #+#             */
/*   Updated: 2023/03/19 02:47:11 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"

size_t print_arr(std::string input)
{
	size_t size = 0;
	std::istringstream ss(input);
	for (std::string line; std::getline(ss, line, ' '); ) {
		if (line.length() > 0) {
	        std::cout << std::stoi(line) << " ";
			size++;
		}
	}
	std::cout << std::endl;
	return size;
}

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

	try
	{
		PmergeMe pme;
		std::vector<int> parsed;
		pme._parse(parsed, expr);
		std::cout << "Before: ";
		size_t size = pme._printContainer(parsed);
		pme.vectorSort(expr);
		std::cout << "After:  ";
		pme.printVector();
		std::cout << "Time to process a range of " << size << " elements with std::vector : " << pme.time_elpased.count() << " us\n";
		pme.dequeSort(expr);
		std::cout << "Time to process a range of " << size << " elements with std::deque  : " << pme.time_elpased.count() << " us\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (EXIT_FAILURE);
	}
}
