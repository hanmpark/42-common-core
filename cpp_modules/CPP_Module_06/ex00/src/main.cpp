/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:43:38 by hanmpark          #+#    #+#             */
/*   Updated: 2024/03/15 19:32:41 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: Wrong number of arguments" << std::endl;
		return 1;
	}
	try {
		std::string	arg(argv[1]);
		ScalarConverter::convert(arg);
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
