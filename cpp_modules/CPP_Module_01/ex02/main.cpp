/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 23:14:44 by hanmpark          #+#    #+#             */
/*   Updated: 2024/04/30 22:11:16 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main() {
	std::string	stringBrain = "HI THIS IS BRAIN";
	std::string	*stringPTR = &stringBrain;
	std::string	&stringREF = stringBrain;

	/* Address of string */
	std::cout << "Address of string in memory: " << &stringBrain << std::endl;
	std::cout << "Address stocked in stringPTR: " << stringPTR << std::endl;
	std::cout << "Address stocked in stringREF: " << &stringREF << std::endl;

	std::cout << std::endl;

	/* Value of string */
	std::cout << "Value of string: " << stringBrain << std::endl;
	std::cout << "Value pointed by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed by stringREF: " << stringREF << std::endl;

	return 0;
}
