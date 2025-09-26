/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:28:27 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:29:35 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << ROSE "[FragTrap] defaultconstructor called" DEF << std::endl;
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy) {
	std::cout << ROSE "[FragTrap] copy constructor called" DEF << std::endl;
	*this = copy;
}

FragTrap::FragTrap(std::string const &Name) : ClapTrap(Name) {
	std::cout << ROSE "[FragTrap] string constructor called" DEF << std::endl;
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
}

FragTrap	&FragTrap::operator=(FragTrap const &rhs) {
	std::cout << ROSE "[FragTrap] copy assignment operator called" DEF << std::endl;
	_Name = rhs.getName();
	_HitPoints = rhs.getHitPoints();
	_EnergyPoints = rhs.getEnergyPoints();
	_AttackDamage = rhs.getAttackDamage();
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << ROSE "[FragTrap] destructor called" DEF << std::endl;
}

void	FragTrap::highFivesGuys() {
	std::cout << ROSE "[FragTrap] Would you mind high fiving me ?" DEF << std::endl;
}
