/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:56:33 by hanmpark          #+#    #+#             */
/*   Updated: 2024/04/30 21:39:19 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static std::string	setZombieName(std::string from) {
	std::string	zombieName;

	std::cout << GREEN "Creating a zombie from the " << from << DEF << std::endl;
	std::cout << "Choose a name for the Zombie: ";
	std::getline(std::cin, zombieName);

	return zombieName;
}

int	main() {
	/* Zombie from heap */
	Zombie *heapZombie = newZombie(setZombieName("heap"));
	heapZombie->announce();
	std::cout << RED << heapZombie->getName() << " doesn't like its name, he prefers Marcus" DEF << std::endl;
	heapZombie->setName("Marcus");
	heapZombie->announce();
	delete heapZombie;

	std::cout << std::endl;

	/* Zombie from stack */
	randomChump(setZombieName("stack"));

	return 0;
}
