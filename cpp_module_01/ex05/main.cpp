/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:07:19 by aperol-h          #+#    #+#             */
/*   Updated: 2022/10/18 21:41:13 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main() {
	Karen		k;

	for (int i = 0; i < 4; i++)
		k.complain(k.getLevels()[i]);
}
