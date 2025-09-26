/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:29:06 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:54:03 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

# include "AForm.hpp"

class AForm;

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

	std::string	getName() const;
	int 		getGrade() const;

	void	incGrade();
	void	decGrade();
	void	signForm(AForm &form) const;
	void	executeForm(AForm const &form);

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