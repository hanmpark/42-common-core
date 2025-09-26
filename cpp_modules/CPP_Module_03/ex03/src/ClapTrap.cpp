/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:02:45 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:29:11 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _Name("NoName"), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0) {
	std::cout << GREEN "[ClapTrap] default constructor called" DEF << std::endl;
}

ClapTrap::ClapTrap(std::string const &Name) : _Name(Name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0) {
	std::cout << GREEN "[ClapTrap] string constructor called" DEF << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy) {
	std::cout << GREEN "[ClapTrap] copy constructor called" DEF << std::endl;
	*this = copy;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs) {
	std::cout << GREEN "[ClapTrap] copy assignment operator called" DEF << std::endl;
	_Name = rhs.getName();
	_HitPoints = rhs.getHitPoints();
	_EnergyPoints = rhs.getEnergyPoints();
	_AttackDamage = rhs.getAttackDamage();
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << GREEN "[ClapTrap] destructor called" DEF << std::endl;
}

void	ClapTrap::attack(std::string const &target) {
	if (_EnergyPoints > 0 && _HitPoints > 0) {
		std::cout << GREEN "[ClapTrap] " << _Name << " attacks " << target << ", causing " << _AttackDamage << " points of damage!" DEF << std::endl;
		_EnergyPoints--;
	} else if (!_EnergyPoints) {
		std::cout << GREEN "[ClapTrap] " << _Name << " has no energy point left to be able to attack." DEF << std::endl;
	} else if (!_HitPoints) {
		std::cout << GREEN "[ClapTrap] " << _Name << " is dead thus it can't attack." DEF << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (_HitPoints > 0) {
		std::cout << GREEN "[ClapTrap] " << _Name << " took " << amount << " damage." DEF << std::endl;
		if (_HitPoints < amount) {
			_HitPoints = 0;
		} else {
			_HitPoints -= amount;
		}
	} else {
		std::cout << GREEN "[ClapTrap] " << _Name << " is already dead. It's an overkill!" DEF << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_EnergyPoints > 0 && _HitPoints > 0) {
		std::cout << GREEN "[ClapTrap] " << _Name << " repaired itself and gained back " << amount << " hits points." DEF << std::endl;
		_HitPoints += amount;
		_EnergyPoints--;
	} else if (!_EnergyPoints) {
		std::cout << GREEN "[ClapTrap] " << _Name << " has no energy point left to repair itself." DEF << std::endl;
	} else if (!_HitPoints) {
		std::cout << GREEN "[ClapTrap] " << _Name << " is dead thus can't repair itself." DEF << std::endl;
	}
}

std::string const	&ClapTrap::getName(void) const { return _Name; }

unsigned int const	&ClapTrap::getHitPoints(void) const { return _HitPoints; }

unsigned int const	&ClapTrap::getEnergyPoints() const { return _EnergyPoints; }

unsigned int const	&ClapTrap::getAttackDamage(void) const { return _AttackDamage; }
