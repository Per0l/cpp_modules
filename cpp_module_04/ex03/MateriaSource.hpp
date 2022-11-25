/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:06:41 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/25 14:30:37 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
private:
    AMateria *_inventory[4];
public:
    MateriaSource();
    MateriaSource(MateriaSource const &copy);
    ~MateriaSource();

    MateriaSource &operator=(MateriaSource const &copy);

    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);
};

#endif
