/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:40:43 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 03:00:15 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy), _target(copy.getName()) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
	(void)rhs;
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm(target, 72, 45), _target(target) {}

void	RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const {
	if (this->getSigned() == false)
		throw AForm::FormUnsignedException();
	else if (this->getGradeToExecute() < bureaucrat.getGrade())
		throw AForm::GradeTooLowException();

	for (int i = 0; i < 3; i++) {
		std::cout << "Bzzzzzz..." << std::endl;
	}

	srand(time(NULL));
	int	num = rand() % 2;
	if (!num)
		std::cout << _target << " has been successfully robotomized !" << std::endl;
	else
		std::cout << _target << " couldn't be robotomized..." << std::endl;
}
