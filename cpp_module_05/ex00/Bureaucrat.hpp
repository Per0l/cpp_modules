/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:37:37 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/13 19:41:52 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>

class Bureaucrat
{
private:
    std::string const _name;
    int _grade;
public:
    Bureaucrat(std::string name, int grade);
    Bureaucrat(Bureaucrat const &copy);
    ~Bureaucrat();

    Bureaucrat const &operator=(Bureaucrat const &copy);

    std::string const getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException: public std::exception {
        public: const char *what() const throw();
    };
    class GradeTooLowException: public std::exception {
        public: const char *what() const throw();
    };

};

std::ostream& operator<<(std::ostream &out, Bureaucrat const &b);

#endif
