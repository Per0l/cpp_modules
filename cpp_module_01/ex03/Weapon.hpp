/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:24:12 by aperol-h          #+#    #+#             */
/*   Updated: 2022/10/17 02:45:51 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon
{
private:
    std::string _type;
public:
    Weapon(std::string type);
    ~Weapon();
    const std::string &getType();
    void setType(std::string type);
};

#endif
