/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:28:52 by hanmpark          #+#    #+#             */
/*   Updated: 2024/03/13 16:23:34 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main() {
	std::cout << "<signing> -------------------------------------" << std::endl;
	{
		try {
			std::cout << "--------------[INFO]--------------" << std::endl;
			Bureaucrat	tom("tom", 5);
			AForm	*shrub = new ShrubberyCreationForm("shrub");
			AForm	*robot = new RobotomyRequestForm("robot");
			AForm	*presi = new PresidentialPardonForm("presi");

			std::cout << tom << std::endl;
			std::cout << *shrub << std::endl;
			std::cout << *robot << std::endl;
			std::cout << *presi << std::endl;
			std::cout << "----------------------------------" << std::endl << std::endl;

			tom.executeForm(*shrub);
			tom.signForm(*shrub);
			std::cout << *shrub << std::endl;
			tom.executeForm(*shrub);
			std::cout << std::endl;

			tom.executeForm(*robot);
			tom.signForm(*robot);
			std::cout << *robot << std::endl;
			tom.executeForm(*robot);
			std::cout << std::endl;

			tom.signForm(*presi);
			std::cout << *presi << std::endl;
			tom.executeForm(*presi);
			delete shrub;
			delete robot;
			delete presi;
		} catch (std::exception &e) {
			std::cout << "An error occurred because " << e.what() << std::endl;
		}
	}
	std::cout << "-----------------------------------------------" << std::endl;
	return 0;
}
