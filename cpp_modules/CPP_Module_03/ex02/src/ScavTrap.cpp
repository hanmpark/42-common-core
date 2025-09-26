/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:18:32 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:29:48 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << PURPLE "[ScavTrap] default constructor called" DEF << std::endl;
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
}

ScavTrap::ScavTrap(std::string const &Name) : ClapTrap(Name) {
	std::cout << PURPLE "[ScavTrap] string constructor called" DEF << std::endl;
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy) {
	std::cout << PURPLE "[ScavTrap] copy constructor called" DEF << std::endl;
	*this = copy;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs) {
	std::cout << PURPLE "[ScavTrap] copy assignment operator called" DEF << std::endl;
	_Name = rhs.getName();
	_HitPoints = rhs.getHitPoints();
	_EnergyPoints = rhs.getEnergyPoints();
	_AttackDamage = rhs.getAttackDamage();
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << PURPLE "[ScavTrap] destructor called" DEF << std::endl;
}

void	ScavTrap::attack(const std::string &target) {
	if (_EnergyPoints > 0) {
		std::cout << PURPLE "[ScavTrap] " << _Name << " attacks " << target << ", causing " << _AttackDamage << " points of damage!" DEF << std::endl;
		_EnergyPoints--;
	} else if (!_EnergyPoints) {
		std::cout << PURPLE "[ScavTrap] " << _Name << " has no energy point left to be able to attack." DEF << std::endl;
	} else if (!_HitPoints) {
		std::cout << PURPLE "[ScavTrap] " << _Name << " is dead thus it can't attack." DEF << std::endl;
	}
}

void	ScavTrap::guardGate() {
	std::cout << PURPLE "[ScavTrap] " << _Name << " is now in Gate keeper mode" DEF << std::endl;
}
