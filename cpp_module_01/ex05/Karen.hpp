/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:08:34 by aperol-h          #+#    #+#             */
/*   Updated: 2022/10/18 21:39:52 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP
# include <iostream>

class Karen
{
private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
    std::string levels[4];
    void (Karen::*funcs_ptr[4])(void);
public:
    Karen();
    ~Karen();
    void complain( std::string level );
    std::string *getLevels();
};

#endif
