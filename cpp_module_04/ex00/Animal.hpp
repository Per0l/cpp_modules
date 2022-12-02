/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 00:24:01 by aperol-h          #+#    #+#             */
/*   Updated: 2022/12/02 18:14:23 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include "colors.hpp"

class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal(Animal const &copy);
    virtual ~Animal();

    Animal &operator=(Animal const &copy);

    std::string getType() const;
    void setType(std::string type);

    virtual void makeSound() const;
};

#endif
