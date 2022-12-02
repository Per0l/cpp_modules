/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 00:25:25 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/25 14:19:49 by aperol-h         ###   ########.fr       */
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
    virtual ~Dog();

    Dog &operator=(Dog const &other);

    Brain* getBrain() const;

    void makeSound() const;
};

#endif
