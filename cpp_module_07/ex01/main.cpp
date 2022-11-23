/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:23:48 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/23 13:28:30 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T>
void print(T v) {
	std::cout << v << std::endl;
}

int main() {
	int i[] = {1,2,3,4,5,6,7,8,9};
	float f[] = {1.9,2.8,3.7,4.6,5.5,6.4,7.3,8.2,9.1};
	std::string s[] = {"Hello", "42", "World", "!"};
	iter(i, sizeof(i)/sizeof(int), print<int>);
	iter(f, sizeof(f)/sizeof(float), print<float>);
	iter(s, sizeof(s)/sizeof(std::string), print<std::string>);
}
