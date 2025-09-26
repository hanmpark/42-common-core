/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:29:06 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:51:33 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

# include "Form.hpp"

class Form;

class Bureaucrat {
private:
	std::string const	_name;
	int					_grade;

public:
	Bureaucrat();
	Bureaucrat(Bureaucrat const &copy);
	~Bureaucrat();
	Bureaucrat	&operator=(Bureaucrat const &rhs);
	Bureaucrat	(std::string const &name, int grade);

	std::string const	getName() const;
	int 				getGrade() const;

	void	incGrade();
	void	decGrade();
	void	signForm(Form &form) const;

	class GradeTooHighException : public std::exception {
	public:
		virtual char const	*what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual char const	*what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif