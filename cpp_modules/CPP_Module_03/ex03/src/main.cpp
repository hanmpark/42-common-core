/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:02:47 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:30:41 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

static void	putSeparator() {

	std::cout << "------------------------------------------------------------" << std::endl;
}

int	main() {

	DiamondTrap Diamond("Diamond");
	FragTrap Fraggy("Fraggy");

	std::cout << std::endl;
	putSeparator();
	std::cout << "Here are Diamond's stats:" << std::endl;
	std::cout	<< "Hit points: " << Diamond.getHitPoints() << std::endl
				<< "Energy points: " << Diamond.getEnergyPoints() << std::endl
				<< "Attack damage: " << Diamond.getAttackDamage() << std::endl;
	putSeparator();
	std::cout << std::endl;

	Diamond.attack("Fraggy");
	Fraggy.takeDamage(Diamond.getAttackDamage());
	Fraggy.attack("Diamond");
	Diamond.takeDamage(Fraggy.getAttackDamage());
	std::cout << std::endl;

	Diamond.beRepaired(3);
	Diamond.guardGate();
	Diamond.highFivesGuys();
	Diamond.whoAmI();
	std::cout << std::endl;
	return 0;
}
