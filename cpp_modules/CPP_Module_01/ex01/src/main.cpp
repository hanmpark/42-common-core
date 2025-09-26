/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:17:52 by hanmpark          #+#    #+#             */
/*   Updated: 2024/04/30 22:11:23 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <sstream>

static int	stringToInt(std::string str) {
	for (size_t i = 0; i < str.size(); i++) {
		if (!std::isdigit(str.at(i))) {
			return -1;
		}
	}
	int	i;
	std::istringstream(str) >> i;
	return i;
}

int	main() {
	std::cout << GREEN "CREATING A HORDE OF ZOMBIES" DEF << std::endl;

	/* Amount of zombies */
	setamount:

	std::string strAmount;
	std::cout << BLUE "Amount of zombies: " DEF;
	std::getline(std::cin, strAmount);

	int zombieAmount;
	if ((zombieAmount = stringToInt(strAmount)) == -1) {
		std::cout << RED "Given arg is not correct" DEF << std::endl;
		goto setamount;
	}

	/* Name of zombies */
	std::string zombieName;
	std::cout << BLUE "Their name: " DEF;
	std::getline(std::cin, zombieName);

	Zombie *horde = zombieHorde(zombieAmount, zombieName);
	for (int i = 0; i < zombieAmount; i++) {
		horde[i].announce();
	}

	delete [] horde;

	return 0;
}
