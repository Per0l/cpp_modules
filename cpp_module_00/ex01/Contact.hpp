/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:30:20 by aperol-h          #+#    #+#             */
/*   Updated: 2022/08/19 17:11:40 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <string>

class Contact
{
private:
	std::string 	data[5];
	int				idx;
public:
	void			set_data(std::string[], int);
	std::string		*get_data();
	int				index();
	bool			exists();
};

#endif
