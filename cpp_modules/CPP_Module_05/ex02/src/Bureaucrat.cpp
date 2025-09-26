/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:29:40 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:55:45 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Some bureaucrat"), _grade(150) {}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : _name(copy._name), _grade(copy._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs) {
	if (this != &rhs)
		_grade = rhs.getGrade();
	return *this;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade) {
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::string	Bureaucrat::getName() const { return _name; }

int	Bureaucrat::getGrade() const { return _grade; }

void	Bureaucrat::incGrade() {
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decGrade() {
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}

void	Bureaucrat::signForm(AForm &form) const {
	try {
		form.beSigned(*this);
		std::cout << *this << " signed " << form.getName() << std::endl;
	} catch (AForm::GradeTooLowException &e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form) {
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << _name << " couldn't execute the " << form.getName() << " because " << e.what() << std::endl;
	}
}

char const	*Bureaucrat::GradeTooHighException::what() const throw() { return "Grade is too high"; }

char const	*Bureaucrat::GradeTooLowException::what() const throw() { return "Grade is too low"; }
