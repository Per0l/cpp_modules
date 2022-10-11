/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:51:55 by aperol-h          #+#    #+#             */
/*   Updated: 2022/08/19 17:30:30 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <sstream>
# include <iomanip>
# define SSTR( x ) dynamic_cast< std::ostringstream & >( \
            ( std::ostringstream() << std::dec << x ) ).str()

class PhoneBook
{
private:
	Contact 	contacts[8];
	std::string	fields[5];
	int			idx;
public:
	void		add(std::string[]);
	void		ADD();
	void		SEARCH();
	PhoneBook();
};

#endif
