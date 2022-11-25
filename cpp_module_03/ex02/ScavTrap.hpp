/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:32:39 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/25 14:05:09 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
protected:
    static unsigned int const _init_hitpoints;
    static unsigned int const _init_energy;
    static unsigned int const _init_damage;
public:
    ScavTrap(std::string name);
    ScavTrap(ScavTrap const &copy);
    ~ScavTrap();

    ScavTrap &operator=(ScavTrap const &copy);

    void attack(std::string const &target);

    void guardGate();
};

#endif
