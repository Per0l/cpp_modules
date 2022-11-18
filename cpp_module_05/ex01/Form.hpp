/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:47:57 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/13 20:40:14 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    std::string const _name;
    int const _gradeSign;
    int const _gradeExecute;
    bool _isSigned;
    void checkGrade();
public:
    Form(std::string name, int gradeSign, int gradeExecute);
    Form(Form const &copy);
    ~Form();

    Form &operator=(Form const &copy);

    std::string const getName() const;
    int getGradeSign() const;
    int getGradeExecute() const;
    bool isSigned() const;

    void beSigned(Bureaucrat const &b);

    class GradeTooHighException: public std::exception {
        public: const char *what() const throw();
    };
    class GradeTooLowException: public std::exception {
        public: const char *what() const throw();
    };
};

std::ostream& operator<<(std::ostream &out, Form const &b);

#endif
