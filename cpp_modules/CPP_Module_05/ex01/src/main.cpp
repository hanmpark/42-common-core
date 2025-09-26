/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:28:52 by hanmpark          #+#    #+#             */
/*   Updated: 2024/03/12 15:58:41 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main() {
	try {
		Bureaucrat	bureaucrat("tom", 49);
		Form		form("Form1", 55);

		std::cout << "Form before: " << std::endl;
		std::cout << form << std::endl << std::endl;
		bureaucrat.signForm(form);
		std::cout << std::endl << "Form after: " << std::endl;
		std::cout << form << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
