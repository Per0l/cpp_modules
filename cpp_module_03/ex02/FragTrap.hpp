/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:51:02 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/06 00:11:10 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
protected:
    static unsigned int const _init_hitpoints;
    static unsigned int const _init_energy;
    static unsigned int const _init_damage;
public:
    FragTrap(std::string name);
    ~FragTrap();

    void attack(std::string const &target);

    void highFivesGuys();
};

#endif
