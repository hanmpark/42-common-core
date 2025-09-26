/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:28:52 by hanmpark          #+#    #+#             */
/*   Updated: 2024/03/12 14:36:05 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main() {
	Bureaucrat	b1;
	Bureaucrat	b2("Mathieu", 1);

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << std::endl;
	try {
		b1.decGrade();
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
