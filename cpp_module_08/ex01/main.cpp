/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:30:24 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/24 18:02:58 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>

int main() {
	std::srand(unsigned(std::time(0)));
	{
		std::cout << "-- Subject example test --" << std::endl;
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.debug();
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest  span: " << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "-- 1000 Random numbers using addNumber --" << std::endl;
		Span sp = Span(1000);
		for (int i = 0; i < 1000; i++)
			sp.addNumber(std::rand());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest  span: " << sp.longestSpan() << std::endl;
		
	}
	{
		std::cout << "-- 500000 Random numbers using range of iterators --" << std::endl;
		std::vector<int> rv(500000);
		std::generate(rv.begin(), rv.end(), std::rand);
		Span sp = Span(500000);
		sp.insert(rv.begin(), rv.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest  span: " << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "-- Not enought numbers exception test --" << std::endl;
		Span sp = Span(10);
		sp.debug();
		try {
			sp.shortestSpan(); sp.longestSpan();
		}
		catch(const std::exception& e) {
			std::cout << "Exception catched: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "-- Number storage full exception test --" << std::endl;
		Span sp = Span(2);
		try {
			sp.addNumber(42);
			sp.addNumber(42);
			sp.addNumber(42);
		}
		catch(const std::exception& e) {
			std::cout << "Exception catched: " << e.what() << std::endl;
		}
		sp.debug();
	}
}
