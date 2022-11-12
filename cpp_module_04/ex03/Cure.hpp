/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:16:33 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/12 21:11:58 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include "ICharacter.hpp"

class Cure: public AMateria
{
public:
    Cure();
    ~Cure();

    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif
