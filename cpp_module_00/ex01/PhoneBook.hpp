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

class PhoneBook
{
private:
	Contact 	contacts[8];
	std::string	fields[5];
	int			idx;
	void		add(std::string[]);
public:
	void		ADD();
	void		SEARCH();
	void 		trim(std::string& str);
	PhoneBook();
};

#endif
