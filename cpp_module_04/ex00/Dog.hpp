/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 00:25:25 by aperol-h          #+#    #+#             */
/*   Updated: 2022/12/02 18:15:24 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class Dog: public Animal
{
public:
    Dog();
    Dog(Dog const &copy);
    virtual ~Dog();

    Dog &operator=(Dog const &copy);

    void makeSound() const;
};

#endif
