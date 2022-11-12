/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:16:50 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/12 21:11:55 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "ICharacter.hpp"

class Ice: public AMateria
{
public:
    Ice();
    ~Ice();

    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif
