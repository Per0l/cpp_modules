/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:37:42 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/15 17:55:01 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void Bureaucrat::checkGrade() {
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade) {
	this->checkGrade();
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy): _name(copy._name), _grade(copy._grade) {
	this->checkGrade();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat const &Bureaucrat::operator=(Bureaucrat const &copy) {
	this->_grade = copy._grade;
	return *this;
}

std::string const Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::setGrade(int grade) {
	this->_grade = grade;
	this->checkGrade();
}

void Bureaucrat::incrementGrade() {
	this->checkGrade();
	this->_grade--;
}

void Bureaucrat::decrementGrade() {
	this->checkGrade();
	this->_grade++;
}

void Bureaucrat::signForm(Form &f) {
	try {
		f.beSigned(*this);
		std::cout << this->_name << " signs " << f.getName() << "." << std::endl;
	}
	catch (std::exception &e) {
		std::cout << this->_name << " cannot sign " << f.getName() << " because: '" << e.what() << "'." << std::endl;
	}
}

void Bureaucrat::executeForm(Form const & form) {
	try {
		form.execute(*this);
	}
	catch (Form::NotSigned &e) {
		std::cout << this->_name << " cannot execute " << form.getName() << " because: '" << e.what() << "'." << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << this->_name << " cannot execute " << form.getName() << " because: '" << e.what() << "'." << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::ostream& operator<<(std::ostream &out, Bureaucrat const &b) {
	out << "(Bureaucrat) " << b.getName() << " | Grade: " << b.getGrade();
	return out;
}
