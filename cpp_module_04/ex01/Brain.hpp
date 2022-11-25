/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 01:05:35 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/25 14:19:12 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include "colors.hpp"

class Brain
{
private:
    std::string ideas[100];
public:
    Brain();
    Brain(Brain const &copy);
    ~Brain();
    
    Brain &operator=(Brain const &other);

    std::string getIdea(int index) const;
};

#endif
