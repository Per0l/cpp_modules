/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 23:55:38 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/30 01:06:49 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>


//https://www.geogebra.org/graphing

int main() {
	Point v1(3.6, 2.2);
	Point v2(3.7, 5.2);
	Point v3(1.05, 3.79);
	Point edge(2.46, 4.54);
	Point in(2.46, 4.53);
	Point in2(2.47, 4.39);

	std::cout << "Vertex 1: " << bsp(v1, v2, v3, v1) << std::endl;
	std::cout << "Vertex 2: " << bsp(v1, v2, v3, v2) << std::endl;
	std::cout << "Vertex 3: " << bsp(v1, v2, v3, v3) << std::endl;
	std::cout << "On edge: " << bsp(v1, v2, v3, edge) << std::endl;
	std::cout << "Inside: " << bsp(v1, v2, v3, in) << std::endl;
	std::cout << "Inside 2: " << bsp(v1, v2, v3, in2) << std::endl;
}
