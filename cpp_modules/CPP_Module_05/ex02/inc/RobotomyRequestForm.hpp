/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:20:31 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:54:14 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	std::string const	_target;

	RobotomyRequestForm();

public:
	RobotomyRequestForm(RobotomyRequestForm const &copy);
	~RobotomyRequestForm();
	RobotomyRequestForm	&operator=(RobotomyRequestForm const &rhs);
	RobotomyRequestForm(std::string const &target);

	void	execute(Bureaucrat const &bureaucrat) const;
};

#endif