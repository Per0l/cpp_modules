/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:43:15 by aperol-h          #+#    #+#             */
/*   Updated: 2022/10/13 15:53:43 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
private:
    std::string     _name;
public:
    Zombie(std::string name);
    ~Zombie();
    void announce(void);
};


Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
