/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 00:57:25 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/25 14:17:29 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
private:

public:
    WrongCat();
    WrongCat(WrongCat const &copy);
    virtual ~WrongCat();

    WrongCat &operator=(WrongCat const &copy);

    void makeSound() const;
};

#endif
