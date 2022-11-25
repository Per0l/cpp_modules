/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:19:10 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/25 14:07:02 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
private:
    std::string _name;
public:
    DiamondTrap(std::string name);
    DiamondTrap(DiamondTrap const &copy);
    ~DiamondTrap();

    DiamondTrap &operator=(DiamondTrap const &copy);
    
    std::string getName() const;

    void whoAmI();

    void attack(std::string const &target);
};

#endif
