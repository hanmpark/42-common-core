/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:54:53 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:15:27 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug() {
	std::cout << YELLOW "[ DEBUG ]" DEF << std::endl;
	std::cout << GREEN DEBUG DEF << std::endl;
	std::cout << std::endl;
}

void	Harl::info() {
	std::cout << YELLOW "[ INFO ]" DEF << std::endl;
	std::cout << GREEN INFO DEF << std::endl;
	std::cout << std::endl;
}

void	Harl::warning() {
	std::cout << YELLOW "[ WARNING ]" DEF << std::endl;
	std::cout << GREEN WARNING DEF << std::endl;
	std::cout << std::endl;
}

void	Harl::error() {
	std::cout << YELLOW "[ ERROR ]" DEF << std::endl;
	std::cout << GREEN ERROR DEF << std::endl;
	std::cout << std::endl;
}

void	Harl::complain(std::string level) {
	std::string	differentLevels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (size_t i = 0; i < 4; i++) {
		if (level == differentLevels[i]) {
			switch (i) {
				case 0: debug();
				case 1: info();
				case 2: warning();
				case 3: error();
				default: break;
			}
		}
	}
}
