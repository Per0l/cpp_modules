/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:49:48 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/22 15:23:25 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>
#include "whatever.hpp"

template <typename T>
void test(T a, T b) {
	std::cout << "Type: " << typeid(T).name() << std::endl;
	std::cout << "a: " << a << " | b: " << b  << std::endl;
	::swap(a, b);
	std::cout << "a: " << a << " | b: " << b  << std::endl;
	std::cout << "min: " << ::min(a, b) << std::endl;
	std::cout << "max: " << ::max(a, b) << std::endl;
	std::cout << std::endl;
}

int main() {
	int a = 1;
	int b = 2;
	test(a, b);
	test(0.259897, 0.512324);
	test(0.2f, 0.5f);
	std::string	a1 = "String A";
	std::string b1 = "String B";
	test(a1, b1);
}
