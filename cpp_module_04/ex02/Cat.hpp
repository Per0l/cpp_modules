/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 00:25:18 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/25 14:21:44 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
private:
    Brain *brain;
public:
    Cat();
    Cat(Cat const &copy);
    virtual ~Cat();

    Cat &operator=(Cat const &other);
    
    Brain* getBrain() const;
    
    void makeSound() const;
};

#endif
