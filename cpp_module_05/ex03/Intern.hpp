/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:22:30 by aperol-h          #+#    #+#             */
/*   Updated: 2022/12/02 21:00:51 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
private:
    static std::string const names[];
    template <class T>
    Form* createForm(std::string const &target);
public:
    Intern();
    Intern(Intern const &copy);
    ~Intern();

    Intern const &operator=(Intern const &copy);

    Form* makeForm(std::string form, std::string target);
    
};

#endif
