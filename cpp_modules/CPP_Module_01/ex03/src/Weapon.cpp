/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 23:26:45 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:13:32 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon) : type(weapon) {}

Weapon::~Weapon(void) {}

std::string const	&Weapon::getType(void) const {

	return type;
}

void	Weapon::setType(std::string newValue) {

	type = newValue;
}
