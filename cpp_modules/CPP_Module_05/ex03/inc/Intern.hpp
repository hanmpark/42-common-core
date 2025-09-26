/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:26:19 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:57:13 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

typedef struct t_dispatch_form {
	std::string const	name;
	AForm				*ret;
}	t_dispatch_form;

class Intern {
public:
	Intern();
	Intern(Intern const &copy);
	~Intern();
	Intern	&operator=(Intern const &rhs);

	AForm	*makeForm(std::string const &formName, std::string const &target);
	class NotFoundFormException : public std::exception {
	public:
		virtual char const *what() const throw();
	};
};

#endif