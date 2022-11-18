/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:47:57 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/18 13:47:29 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"
# include <fstream>
# include <cstdlib>
# include <sys/time.h>

class Bureaucrat;

class Form
{
private:
    std::string const _name;
    std::string const _target;
    int const _gradeSign;
    int const _gradeExecute;
    bool _isSigned;
    void checkGrade();
public:
    Form(std::string name, std::string target, int gradeSign, int gradeExecute);
    Form(Form const &copy);
    ~Form();

    Form &operator=(Form const &copy);

    std::string const getName() const;
    std::string const getTarget() const;
    int getGradeSign() const;
    int getGradeExecute() const;
    bool isSigned() const;

    void beSigned(Bureaucrat const &b);
    void execute(Bureaucrat const & executor) const;
    virtual void run() const = 0;

    class GradeTooHighException: public std::exception {
        public: const char *what() const throw();
    };
    class GradeTooLowException: public std::exception {
        public: const char *what() const throw();
    };
    class NotSigned: public std::exception {
        public: const char *what() const throw();
    };
};

std::ostream& operator<<(std::ostream &out, Form const &b);

#endif
