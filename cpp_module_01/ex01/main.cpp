/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:43:32 by aperol-h          #+#    #+#             */
/*   Updated: 2022/10/17 02:42:18 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	int	size;

	size = 20;
	Zombie *horde = zombieHorde(size, "test");
	for (int i = 0; i < size; i++)
		horde[i].announce();
	delete [] horde;
}
