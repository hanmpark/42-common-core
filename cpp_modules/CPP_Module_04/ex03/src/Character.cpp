/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:13:23 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:48:38 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("* no name *") {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
	_ground = NULL;
	std::cout << GREEN "[Character] " << _name << " has been created" DEF << std::endl;
}

Character::Character(Character const &copy) : _name(copy._name) {
	*this = copy;
	std::cout << GREEN "[Character] " << _name << " has been created" DEF << std::endl;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i]) {
			delete _inventory[i];
		}
	}
	if (_ground) {
		delete [] _ground;
		_ground = NULL;
	}
	std::cout << GREEN "[Character] " << _name << " has been destroyed" DEF << std::endl;
}

Character	&Character::operator=(Character const &rhs) {
	std::cout << "[Character] Copy assignment operator called" << std::endl;

	if (this != &rhs) {
		_name = rhs._name;
		if (_ground) {
			delete [] _ground;
		}
		_ground = NULL;

		int count = 0;
		while (rhs._ground[count]) {
			count++;
		}
		_ground = new AMateria*[count];
		for (int i = 0; rhs._ground[i]; i++) {
			_ground[i] = rhs._ground[i];
		}

		for (int i = 0; _inventory[i]; i++) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
		for (int i = 0; i < 4; i++) {
			_inventory[i] = rhs._inventory[i];
		}
	}
	return *this;
}

Character::Character(std::string const &name) : _name(name) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
	_ground = NULL;
	std::cout << GREEN "[Character] " << _name << " has been created" DEF << std::endl;
}

std::string const	&Character::getName() const { return _name; }

void	Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			std::cout << GREEN "[Character] " << _name << " has equipped " << m->getType() << DEF << std::endl;
			return;
		}
	}
	std::cout << RED "[Character] " << _name << " has no place left in his inventory to equip " << m->getType() << DEF << std::endl;
	delete m;
	m = NULL;
}

int	Character::countGroundItem() const {
	int	count = 1;
	int	i = 0;

	while (_ground && _ground[i++]) {
		count++;
	}
	return count;
}

void	Character::updateGround(AMateria *unequippedAmateria) {
	int	groundItemNbr = countGroundItem();

	AMateria	**newGround = new AMateria*[groundItemNbr + 1];

	for (int i = 0; i < groundItemNbr - 1; i++) {
		newGround[i] = _ground[i];
	}
	if (_ground) {
		delete _ground;
		_ground = NULL;
	}
	newGround[groundItemNbr - 1] = unequippedAmateria;
	newGround[groundItemNbr] = NULL;
	_ground = newGround;
}

void	Character::reorderItems() {
	int	i = 0;

	while (i < 3) {
		if (!_inventory[i] && _inventory[i + 1]) {
			_inventory[i] = _inventory[i + 1];
			_inventory[i + 1] = NULL;
		}
		i++;
	}
}

void	Character::unequip(int idx) {
	if ((idx >= 0 && idx <= 3) && _inventory[idx]) {
		updateGround(_inventory[idx]->clone());
		delete _inventory[idx];
		_inventory[idx] = NULL;
		reorderItems();
		std::cout << GREEN "[Character] " << _name << " has unequipped an item at slot " << idx << DEF << std::endl;
		return;
	}
	std::cout << RED "[Character] " << _name << " doesn't have any equipment at slot " << idx << DEF << std::endl;
}

void	Character::use(int idx, ICharacter &target) {
	if ((idx >= 0 && idx <= 3) && _inventory[idx]) {
		_inventory[idx]->use(target);
		std::cout << GREEN "[Character] " << _name << " uses " << _inventory[idx]->getType() << DEF << std::endl;
		return;
	}
	std::cout << RED "[Character] " << _name << " doesn't have any equipment at slot " << idx << DEF << std::endl;
}

void	Character::checkground() const {
	std::cout << BLUE "[Character] on the ground: ";
	for (int i = 0; _ground[i]; i++) {
		std::cout << "[" << _ground[i]->getType() << "]";
		if (_ground[i + 1]) {
			std::cout << ", ";
		}
	}
	std::cout << DEF << std::endl;
}
