/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:17:32 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:28:56 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("NoName_clap_name"), FragTrap(), ScavTrap() {
	std::cout << YELLOW "[DiamondTrap] default constructor called" DEF << std::endl;
	_Name = "NoName";
	_HitPoints = _FragHitPoints;
	_EnergyPoints = _ScavEnergyPoints;
	_AttackDamage = _FragAttackDamage;
}

DiamondTrap::DiamondTrap(std::string const &Name) : ClapTrap(Name + "_clap_name"), FragTrap(Name), ScavTrap(Name) {
	std::cout << YELLOW "[DiamondTrap] string constructor called" DEF << std::endl;
	_Name = Name;
	_HitPoints = _FragHitPoints;
	_EnergyPoints = _ScavEnergyPoints;
	_AttackDamage = _FragAttackDamage;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy) {
	std::cout << YELLOW "[DiamondTrap] copy constructor called" DEF << std::endl;
	*this = copy;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &rhs) {
	std::cout << YELLOW "[DiamondTrap] copy assignment operator called" DEF << std::endl;
	_Name = rhs.getName();
	ClapTrap::_Name = rhs.getName() + "_clap_name";
	_HitPoints = rhs.getHitPoints();
	_EnergyPoints = rhs.getEnergyPoints();
	_AttackDamage = rhs.getAttackDamage();
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << YELLOW "[DiamondTrap] destructor called" << std::endl;
}

void	DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI() {
	std::cout << YELLOW "[DiamondTrap] My Name is " << _Name << " and my ClapTrap name is " << ClapTrap::_Name << std::endl;
}
