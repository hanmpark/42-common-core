/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:02:47 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:23:40 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

static void	putSeparator() {
	std::cout << "------------------------------------------------------------" << std::endl;
}

int	main() {
	ClapTrap	Clappy("Clappy");
	ScavTrap	Scavy("Scavy");

	std::cout << std::endl;
	putSeparator();
	Clappy.attack("Scavy");
	Scavy.takeDamage(Clappy.getAttackDamage());
	putSeparator();
	std::cout << std::endl;

	putSeparator();
	std::cout << "Now it is Scavy's turn to attack Clappy!" << std::endl;
	Scavy.attack("Clappy");
	Clappy.takeDamage(Scavy.getAttackDamage());
	Clappy.attack("Scavy");
	Scavy.takeDamage(Clappy.getAttackDamage());
	putSeparator();
	std::cout << std::endl;

	putSeparator();
	std::cout << "A new foe has appeared!" << std::endl;
	ScavTrap newfoe(Scavy);
	newfoe.attack("Clappy");
	Clappy.takeDamage(newfoe.getAttackDamage());
	newfoe.guardGate();
	Clappy.beRepaired(10);
	putSeparator();
	std::cout << std::endl;
	return 0;
}
