/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:16:33 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/25 14:28:52 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include "ICharacter.hpp"

class Cure: public AMateria
{
public:
    Cure();
    Cure(Cure const &copy);
    ~Cure();

    Cure &operator=(Cure const &copy);

    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif
