/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:02:47 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:29:41 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

static void	putSeparator() {
	std::cout << "------------------------------------------------------------" << std::endl;
}

static void	presentTraps(ClapTrap &Clappy, ScavTrap &Scavy, FragTrap &Fraggy) {
	putSeparator();
	std::cout << Clappy.getName() << " has " << Clappy.getHitPoints() << " hitpoints, " << Clappy.getEnergyPoints() << " energy points and " << Clappy.getAttackDamage() << " attack damage." << std::endl;
	std::cout << Scavy.getName() << " has " << Scavy.getHitPoints() << " hitpoints, " << Scavy.getEnergyPoints() << " energy points and " << Scavy.getAttackDamage() << " attack damage." << std::endl;
	std::cout << Fraggy.getName() << " has " << Fraggy.getHitPoints() << " hitpoints, " << Fraggy.getEnergyPoints() << " energy points and " << Fraggy.getAttackDamage() << " attack damage." << std::endl;
	putSeparator();
	std::cout << std::endl;
}

int	main() {
	ClapTrap	Clappy("Clappy");
	ScavTrap	Scavy("Scavy");
	FragTrap	Fraggy("Fraggy");

	std::cout << std::endl;

	presentTraps(Clappy, Scavy, Fraggy);

	Scavy.attack("Fraggy");
	Fraggy.takeDamage(Scavy.getAttackDamage());
	std::cout << "Now Fraggy is mad and attacks Scavy back" << std::endl;
	Fraggy.attack("Scavy");
	Scavy.takeDamage(Fraggy.getAttackDamage());
	std::cout << std::endl;

	presentTraps(Clappy, Scavy, Fraggy);

	std::cout << "Clappy is unhappy about his friends fighting each other." << std::endl;
	Clappy.attack("Scavy and Fraggy");
	Scavy.takeDamage(Clappy.getAttackDamage());
	Fraggy.takeDamage(Clappy.getAttackDamage());
	std::cout << std::endl;
	std::cout << "Both Scavy and Fraggy counters the attack of Clappy" << std::endl;
	Scavy.attack("Clappy");
	Fraggy.attack("Clappy");
	Clappy.takeDamage(Scavy.getAttackDamage());
	Clappy.takeDamage(Fraggy.getAttackDamage());
	std::cout << std::endl;

	presentTraps(Clappy, Scavy, Fraggy);
	return 0;
}
