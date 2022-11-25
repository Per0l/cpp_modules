/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 00:25:18 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/25 14:14:05 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat: public Animal
{
private:

public:
    Cat();
    Cat(Cat const &copy);
    virtual ~Cat();

    Cat &operator=(Cat const &copy);

    void makeSound() const;
};

#endif
