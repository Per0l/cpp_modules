/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:51:02 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/25 14:06:20 by aperol-h         ###   ########.fr       */
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
    FragTrap(FragTrap const &copy);
    ~FragTrap();

    FragTrap &operator=(FragTrap const &copy);

    void attack(std::string const &target);

    void highFivesGuys();
};

#endif
