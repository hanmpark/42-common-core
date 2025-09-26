/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:17:51 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:57:49 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
	std::string const	_target;

	ShrubberyCreationForm();

public:
	ShrubberyCreationForm(ShrubberyCreationForm const &copy);
	~ShrubberyCreationForm();
	ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);
	ShrubberyCreationForm(std::string const &target);

	void	execute(Bureaucrat const &bureaucrat) const;

	class CreateFileException : public std::exception {
	public:
		virtual char const	*what() const throw();
	};
};

#endif