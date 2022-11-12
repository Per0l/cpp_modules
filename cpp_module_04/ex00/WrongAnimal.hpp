/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 00:57:43 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/06 01:01:53 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

# define RESET "\033[0m"
# define GRAY "\x1B[90m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define MAGENTA "\x1B[35m"
# define CYAN "\x1B[36m"
# define BBLUE "\x1B[94m"
# define BCYAN "\x1B[96m"
# define UNDERLINE "\x1B[4m"
# define BG_BLACK "\x1B[40m"

class WrongAnimal
{
protected:
    std::string type;
public:
    WrongAnimal();
    virtual ~WrongAnimal();

    std::string getType() const;
    void setType(std::string type);

    void makeSound() const;
};

#endif
