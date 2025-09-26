/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:54:36 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:15:34 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static bool	isLevel(std::string chosenLevel) {
	return chosenLevel == "DEBUG" || chosenLevel == "INFO" \
		|| chosenLevel == "WARNING" || chosenLevel == "ERROR";
}

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << RED "Error: Wrong number of arguments" DEF << std::endl;
		return 1;
	}

	if (!isLevel(argv[1])) {
		std::cout << RED "[ Probably complaining about insignificant problems ]" DEF << std::endl;
		return 0;
	}

	Harl	harl;
	harl.complain(argv[1]);

	return 0;
}
