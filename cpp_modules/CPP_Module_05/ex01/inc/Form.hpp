/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:38:08 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:51:43 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	std::string const	_name;
	bool				_signed;
	int const			_gradeToSign;
	int const			_gradeToExecute;

	Form();

public:
	Form(Form const &copy);
	~Form();
	Form	&operator=(Form const &rhs);
	Form(std::string const &name, int gradeToSign);

	std::string const	getName() const;
	bool				getSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;

	void	beSigned(Bureaucrat const &bureaucrat);

	class GradeTooHighException : public std::exception {
	public:
		virtual char const	*what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual char const	*what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, Form const &rhs);

#endif