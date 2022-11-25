/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:41:47 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/25 13:54:24 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

# define RESET "\033[0m"
# define GRAY "\x1B[90m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define MAGENTA "\x1B[35m"
# define CYAN "\x1B[36m"
# define BBLUE "\x1B[94m"
# define UNDERLINE "\x1B[4m"
# define BG_BLACK "\x1B[40m"

class ClapTrap
{
private:
    std::string _name;
    unsigned int _hitpoints;
    unsigned int _energy;
    unsigned int _damage;
public:
    ClapTrap(std::string name);
    ClapTrap(ClapTrap const &copy);
    ~ClapTrap();

    ClapTrap &operator=(ClapTrap const &copy);

    virtual std::string getName() const;
    unsigned int getHitpoints() const;
    unsigned int getEnergy() const;
    unsigned int getDamage() const;

    void setName(std::string name);
    void setHitpoints(unsigned int amount);
    void setEnergy(unsigned int amount);
    void setDamage(unsigned int amount);

    virtual void attack(std::string const &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

std::ostream &operator<<(std::ostream &out, ClapTrap const &trap);

#endif
