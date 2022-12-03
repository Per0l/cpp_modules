/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:54:05 by aperol-h          #+#    #+#             */
/*   Updated: 2022/12/03 16:01:13 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <cstdlib>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
	struct timeval time_now;
	gettimeofday(&time_now, 0);
	time_t msecs_time = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
	srand(static_cast<unsigned int>(msecs_time));

	Base *ptr;
	int r = rand() % 3;
	switch (r)
	{
	case 0:
		ptr = new A();
		break;
	case 1:
		ptr = new B();
		break;
	default:
		ptr = new C();
		break;
	}
	return ptr;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	
}

void identify(Base& p) {
	try {
		A c = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e){}
	try {
		B c = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e){}
	try {
		C c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e){}
}

int main() {
	Base *ptr = generate();
	std::cout << "Pointer: " << std::endl;
	identify(ptr);
	std::cout << "Reference: " << std::endl;
	identify(*ptr);
	delete ptr;
}
