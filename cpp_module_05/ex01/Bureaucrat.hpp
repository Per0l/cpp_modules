/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:37:37 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/13 20:35:37 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat
{
private:
    std::string const _name;
    int _grade;
    void checkGrade();
public:
    Bureaucrat(std::string name, int grade);
    Bureaucrat(Bureaucrat const &copy);
    ~Bureaucrat();

    Bureaucrat const &operator=(Bureaucrat const &copy);

    std::string const getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    void signForm(Form &f);

    class GradeTooHighException: public std::exception {
        public: const char *what() const throw();
    };
    class GradeTooLowException: public std::exception {
        public: const char *what() const throw();
    };

};

std::ostream& operator<<(std::ostream &out, Bureaucrat const &b);

#endif
