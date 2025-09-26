/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 23:26:37 by hanmpark          #+#    #+#             */
/*   Updated: 2024/04/30 22:15:59 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

#include <stddef.h>

HumanB::HumanB(std::string name) : _name(name) {
	_weapon = NULL;
}

void HumanB::attack() const {
	if (_weapon == NULL) {
		std::cout << _name << " doesn't have any weapon" << std::endl;
	} else {
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	}
}

void HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}
