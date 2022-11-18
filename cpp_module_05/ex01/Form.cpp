/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:47:54 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/15 17:51:16 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

void Form::checkGrade() {
	if (this->_gradeSign < 1 || this->_gradeExecute < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_gradeSign > 150 || this->_gradeExecute > 150)
		throw Bureaucrat::GradeTooLowException();
}

Form::Form(std::string name, int gradeSign, int gradeExecute): _name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute), _isSigned(0) {
	this->checkGrade();
}

Form::Form(Form const &copy): _name(copy._name), _gradeSign(copy._gradeSign), _gradeExecute(copy._gradeExecute), _isSigned(copy._isSigned) {
	this->checkGrade();
}

Form::~Form() {}

Form &Form::operator=(Form const &copy) {
	this->_isSigned = copy._isSigned;
	return *this;
}

std::string const Form::getName() const {
	return this->_name;
}

int Form::getGradeSign() const {
	return this->_gradeSign;
}

int Form::getGradeExecute() const {
	return this->_gradeExecute;
}

bool Form::isSigned() const {
	return this->_isSigned;
}

void Form::beSigned(Bureaucrat const &b) {
	if (b.getGrade() <= this->_gradeSign)
		this->_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::ostream& operator<<(std::ostream &out, Form const &f) {
	std::string signedStr = f.isSigned() ? "Yes" : "No";
	out << "(Form) " << f.getName() << " | Grade to sign: " << f.getGradeSign();
	out << " | Grade to execute: " << f.getGradeExecute();
	out << " | Signed: " << signedStr;
	return out;
}
