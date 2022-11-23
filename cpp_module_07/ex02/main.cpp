/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:29:28 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/23 14:14:09 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main() {
	std::cout << "-- Test Int --" << std::endl;
	{
		Array<int> a(15);
		std::cout << "Array a: ";
		for (unsigned int i = 0; i < a.size(); i++) {
			a[i] = (i + 1) * 2;
			std::cout << a[i] << " ";
		}
		std::cout << "\nArray b created from Array a." << std::endl;
		Array<int> b(a);
		std::cout << "Assigned all Array a elements to 0 " << std::endl;
		for (unsigned int i = 0; i < a.size(); i++) {
			a[i] = 0;
		}
		std::cout << "Array b: ";
		for (unsigned int i = 0; i < b.size(); i++)
			std::cout << b[i] << " ";
		std::cout << "\nArray a: ";
		for (unsigned int i = 0; i < a.size(); i++) {
			std::cout << a[i] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "-- Test Float --" << std::endl;
	{
		Array<float> a(15);
		std::cout << "Array a: ";
		for (unsigned int i = 0; i < a.size(); i++) {
			a[i] = (i + 1) * 1.5;
			std::cout << a[i] << " ";
		}
		std::cout << "\nArray b created from Array a." << std::endl;
		Array<float> b(a);
		std::cout << "Assigned all Array a elements to 0 " << std::endl;
		for (unsigned int i = 0; i < a.size(); i++) {
			a[i] = 0;
		}
		std::cout << "Array b: ";
		for (unsigned int i = 0; i < b.size(); i++)
			std::cout << b[i] << " ";
		std::cout << "\nArray a: ";
		for (unsigned int i = 0; i < a.size(); i++) {
			std::cout << a[i] << " ";
		}
		std::cout << std::endl;
	}
}
