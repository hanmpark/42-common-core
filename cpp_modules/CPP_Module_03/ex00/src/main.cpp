/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:02:47 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:23:45 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

static void	putSeparator() {
	std::cout << "------------------------------------------------------------" << std::endl;
}

int	main() {
	ClapTrap	Clappy1("Clappy1");
	ClapTrap	Clappy2("Clappy2");

	std::cout << std::endl;
	putSeparator();
	std::cout << "Clappy1 attacking Clappy2 11 times:" << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 11; i++) {
		Clappy1.attack("Clappy2");
		Clappy2.takeDamage(Clappy1.getAttackDamage());
	}
	putSeparator();
	std::cout << std::endl;

	Clappy1.beRepaired(5);
	Clappy2.beRepaired(5);
	std::cout << "Clappy1 has " << Clappy1.getHitPoints() << " hit points." << std::endl;
	std::cout << "Clappy2 has " << Clappy2.getHitPoints() << " hit points." << std::endl;
	std::cout << std::endl;

	ClapTrap	CopyClap(Clappy2);
	std::cout << "Object CopyClap is called " << CopyClap.getName() << " and has " << CopyClap.getHitPoints() << std::endl;
	std::cout << std::endl;
	return 0;
}
