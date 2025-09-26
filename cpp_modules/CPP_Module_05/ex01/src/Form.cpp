/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:46:44 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:53:15 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(Form const &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {}

Form::~Form() {}

Form	&Form::operator=(Form const &rhs) {
	if (this != &rhs)
		_signed = rhs._signed;
	return *this;
}

Form::Form(std::string const &name, int gradeToSign) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(0) {
	if (_gradeToSign < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_gradeToSign > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::string const	Form::getName() const {
	return _name;
}

bool	Form::getSigned() const {
	return _signed;
}

int	Form::getGradeToSign() const {
	return _gradeToSign;
}

int	Form::getGradeToExecute() const {
	return _gradeToExecute;
}

std::ostream	&operator<<(std::ostream &o, Form const &rhs) {
	o << "[Form " << rhs.getName() << " info]" << std::endl;
	o << "Form grade is signed: " << (rhs.getSigned() == true ? "true" : "false") << std::endl;
	o << "Form grade to sign: " << rhs.getGradeToSign() << std::endl;
	o << "Form grade to execute: " << rhs.getGradeToExecute();
	return o;
}

void	Form::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

char const	*Form::GradeTooHighException::what() const throw() { return "Grade is too high"; }

char const	*Form::GradeTooLowException::what() const throw() { return "Grade is too Low"; }
