/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:22:36 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:54:09 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	std::string const	_target;

	PresidentialPardonForm();

public:
	PresidentialPardonForm(PresidentialPardonForm const &copy);
	~PresidentialPardonForm();
	PresidentialPardonForm	&operator=(PresidentialPardonForm const &rhs);
	PresidentialPardonForm(std::string const &target);

	void	execute(Bureaucrat const &bureaucrat) const;
};

#endif