/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 00:25:25 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/06 14:52:02 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
private:
    Brain *brain;
public:
    Dog();
    Dog(Dog const &copy);
    Dog &operator=(Dog const &other);
    virtual ~Dog();

    Brain* getBrain() const;

    void makeSound() const;
};

#endif
