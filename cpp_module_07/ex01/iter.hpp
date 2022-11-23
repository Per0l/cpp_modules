/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:24:04 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/22 18:45:04 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template<typename T, typename S, typename F>
void iter(T array, S size, F f) {
	if (!array || !f)
		return;
	for (S i = 0; i < size; i++)
		f(array[i]);
}

#endif
