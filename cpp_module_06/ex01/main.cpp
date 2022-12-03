/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:26:56 by aperol-h          #+#    #+#             */
/*   Updated: 2022/12/03 15:45:47 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <iostream>

struct Data
{
	int i;
	float f;
};

uintptr_t serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

int main() {
	Data *data = new Data();
	data->f = 3.14;
	data->i = 42;


	std::cout << "Original data address:\t\t" << data << "\t(i: " << data->i << ", f: " << data->f << ")" << std::endl;
	uintptr_t sdata = serialize(data);
	std::cout << "Serialized data value:\t\t" << sdata << std::endl;
	Data *udata = deserialize(sdata);
	std::cout << "De-Serialized data address:\t" << udata << "\t(i: " << udata->i << ", f: " << udata->f << ")" << std::endl;
}
