/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:54:53 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:14:54 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug() {
	std::cout << GREEN DEBUG DEF << std::endl;
}

void	Harl::info() {
	std::cout << GREEN INFO DEF << std::endl;
}

void	Harl::warning() {
	std::cout << GREEN WARNING DEF << std::endl;
}

void	Harl::error() {
	std::cout << GREEN ERROR DEF << std::endl;
}

void	Harl::complain(std::string level) {
	Level const complainHarl[] = {
		{&Harl::debug, "DEBUG"},
		{&Harl::info, "INFO"},
		{&Harl::warning, "WARNING"},
		{&Harl::error, "ERROR"}
	};

	for (size_t i = 0; i < 4; i++) {
		if (level == complainHarl[i].level) {
			(*complainHarl[i].complainLevel)();
		}
	}
}
