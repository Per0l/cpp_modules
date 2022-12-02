/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 00:57:43 by aperol-h          #+#    #+#             */
/*   Updated: 2022/12/02 18:15:37 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>
# include "colors.hpp"

class WrongAnimal
{
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(WrongAnimal const &copy);
    virtual ~WrongAnimal();

    WrongAnimal &operator=(WrongAnimal const &copy);

    std::string getType() const;
    void setType(std::string type);

    void makeSound() const;
};

#endif
