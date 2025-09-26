/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:28:52 by hanmpark          #+#    #+#             */
/*   Updated: 2024/03/14 10:47:29 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main() {
	std::cout << "<intern> --------------------------------------" << std::endl;
	{
		try {
			Intern	mathieu;
			AForm	*shrub = mathieu.makeForm("shrubbery creation", "shrub");
			std::cout << *shrub << std::endl;
			delete shrub;
			AForm	*random = mathieu.makeForm("oui", "lol");
			std::cout << *random << std::endl;
			delete random;
		} catch (std::exception &e) {
			std::cerr << "An error occurred because " << e.what() << std::endl;
		}
	}
	std::cout << "-----------------------------------------------" << std::endl;
	return 0;
}
